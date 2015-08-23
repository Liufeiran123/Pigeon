/*
 * indexsearch.cpp
 *
 *  Created on: 2015年8月21日
 *      Author: liuqiang
 */

#include "indexsearch.h"

index_search *index_search::is = NULL;

index_search::index_search(char *indexdb_dir):db(indexdb_dir,Xapian::DB_CREATE_OR_OPEN),enquire(db) {
	// TODO Auto-generated constructor stub


}

index_search::~index_search() {
	// TODO Auto-generated destructor stub
}

index_search* index_search::getInstance()
{
	if(is != NULL)
	{
		return is;
	}
	is = new index_search("/Users/liuqiang/PycharmProjects/Pigeon/index_data/");
	return is;
}

void index_search::index(unsigned int id,items &t)
{
	Document doc;
	for(items::const_iterator it = t.begin();it != t.end();++it)
	{
		doc.add_term(it->first);
	}
	db.replace_document(id,doc);
}
void index_search::update_index(unsigned int id,items &t)
{
	Document doc = db.get_document(id);

	doc.clear_terms();
	for(items::const_iterator it = t.begin();it != t.end();++it)
	{
		doc.add_term(it->first);
	}

	db.replace_document(id, doc);

}
void index_search::search(search_key &t,result &r,int offset,int limit)
{
	Query query(Xapian::Query::OP_OR, t.begin(), t.end());
	enquire.set_query(query);
	MSet matches = enquire.get_mset(offset, limit, 10000);
	for (Xapian::MSetIterator i = matches.begin(); i != matches.end(); ++i)
	{
		r.push_back(i.get_document().get_docid());
	}
}
