//============================================================================
// Name        : IndexServer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <assert.h>
#include <iostream>
#include <pthread.h>
#include <zmq.h>
#include "tinyxml.h"
#include "index_msg.pb.h"
#include "indexsearch.h"
#include "search_msg.pb.h"
using namespace std;

void* index_thread(void* ptr)
{
	char *str = (char*)ptr;
	index_msg im;
	if(im.ParseFromString(str))
	{
		items it;
		for(int i  = 0;i< im.single_item_size() ;++i)
		{
			const SingleItem ii = im.single_item(i);
			it.insert(items::value_type(ii.item(),ii.num()));
		}
		index_search::getInstance()->index(im.max_id(),it);
	}
	delete [] str;
}


int main(int argc,char *argv[])
{
	//配置文件

	const char* filepath = "/Users/liuqiang/PycharmProjects/Pigeon/config/index.xml";
	TiXmlDocument doc(filepath);
	bool loadOkay = doc.LoadFile();
	// faile to load 'phonebookdata.xml'.
	if (!loadOkay) {
	    printf( "Could not load test file %s. Error='%s'. Exiting.\n", filepath,doc.ErrorDesc() );
	    exit( 1 );
	}

	TiXmlElement* root = doc.RootElement();
	TiXmlNode *item = root->FirstChild();

	 TiXmlNode* child = item->FirstChild();
	 const char *index_ip = child->ToElement()->GetText();
	 child = item->IterateChildren(child);
	 const char *index_port = child->ToElement()->GetText();

	 const char *indexdb = "/Users/liuqiang/PycharmProjects/Pigeon/index_data";

	 item = item->NextSibling();
	 child = item->FirstChild();
	 const char *search_ip = child->ToElement()->GetText();
	 child = item->IterateChildren(child);
	 const char *search_port = child->ToElement()->GetText();

	void *ctx;
	ctx = zmq_init(1);
	assert(ctx);

	void *s1;
	s1 = zmq_socket(ctx,ZMQ_PULL);
	assert(s1);

	void *s2;
	s2 = zmq_socket(ctx,ZMQ_REP);
	assert(s2);

	string index_addr="tcp://";
	index_addr.append(index_ip);
	index_addr.append(":");
	index_addr.append(index_port);

	string search_addr="tcp://";
	search_addr.append(search_ip);
	search_addr.append(":");
	search_addr.append(search_port);

	zmq_bind(s1,index_addr.c_str());
	zmq_bind(s2,search_addr.c_str());

	cout<<"Starting...."<<endl;

	while(1)
	{
		zmq_pollitem_t items[2];
		items[0].socket = s1;
		items[0].fd = 0;
		items[0].events = ZMQ_POLLIN;

		items[1].socket = s2;
		items[1].fd = 0;
		items[1].events = ZMQ_POLLIN;
		cout<< "zmq_poll"<<endl;
		int nRet = zmq_poll(items,2,-1);
		if(0 == nRet)
			continue;

		zmq_msg_t msg;

		if(items[0].revents > 0)
		{
		//index
			cout<<"recv index"<<endl;
			pthread_t pid;
			zmq_msg_init(&msg);
			zmq_msg_recv(&msg,s1,0);
			char *re_string = new char[zmq_msg_size(&msg)];
			memcpy(re_string,(char*)zmq_msg_data(&msg),zmq_msg_size(&msg));
			int ret = pthread_create(&pid, NULL, index_thread, (void*)re_string);
			if(ret < 0)
			{
				delete[] re_string;
			}
			zmq_msg_close(&msg);
		}

		if(items[1].revents > 0)
		{
		//search
			cout<<"recv search"<<endl;
			result r;
			search_key t;
			zmq_msg_init(&msg);
			zmq_msg_recv(&msg,s2,0);
			char *re_string = new char[zmq_msg_size(&msg)];
			memcpy(re_string,(char*)zmq_msg_data(&msg),zmq_msg_size(&msg));
			search_msg sm;
			if(sm.ParseFromString(re_string))
			{
				for(int i  = 0;i< sm.word_size() ;++i)
				{
					t.push_back(sm.word(i));
				}
				index_search::getInstance()->search(t,r);
				search_result sr;
				for(result::const_iterator it = r.begin();it != r.end();++it)
				{
					sr.add_id(*it);
				}
				string buffer;
				sr.SerializeToString(&buffer);
				memcpy(zmq_msg_data(&msg),buffer.c_str(),buffer.size());
				zmq_msg_send(&msg,s2,0);
			}

			search_result sr;
			sr.add_id(-10);
			string buffer;
			sr.SerializeToString(&buffer);
			memcpy(zmq_msg_data(&msg),buffer.c_str(),buffer.size());
			zmq_msg_send(&msg,s2,0);
			delete[] re_string;
			zmq_msg_close(&msg);
			cout<<"search send over"<<endl;
		}
	}

	zmq_close(s1);
	zmq_close(s2);
	zmq_term(ctx);
}
