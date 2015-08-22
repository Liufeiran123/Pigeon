/*
 * indexsearch.h
 *
 *  Created on: 2015年8月21日
 *      Author: liuqiang
 */

#ifndef INDEXSEARCH_H_
#define INDEXSEARCH_H_

#include <xapian.h>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;
using namespace Xapian;

typedef unordered_map<string,unsigned int> items;
typedef list<string> search_key;
typedef list<int> result;

class index_search {
public:
	index_search(char *indexdb_dir);
	virtual ~index_search();
private:
	static index_search *is;
public:
	static index_search *getInstance();
private:
	WritableDatabase db;
	Enquire enquire;

public:

	void index(unsigned int id, items &t);
	void update_index(unsigned int id,items &t);
	void search(search_key &s,result &r,int offset = 0,int limit = 10);
};

#endif /* INDEXSEARCH_H_ */
