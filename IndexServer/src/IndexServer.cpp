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
#include <zmq.hpp>
#include "tinyxml.h"
#include "index_msg.pb.h"
#include "indexsearch.h"
#include "search_msg.pb.h"
using namespace std;
using namespace zmq;

void* index_thread(void* ptr) {
	char *str = (char*) ptr;
	index_msg im;
	if (im.ParseFromString(str)) {
		items it;
		for (int i = 0; i < im.single_item_size(); ++i) {
			const SingleItem ii = im.single_item(i);
			it.insert(items::value_type(ii.item(), ii.num()));
		}
		index_search::getInstance()->index(im.max_id(), it);
	}
	delete[] str;
}

int main(int argc, char *argv[]) {
	//配置文件

	const char* filepath =
			"/Users/liuqiang/PycharmProjects/Pigeon/config/index.xml";
	TiXmlDocument doc(filepath);
	bool loadOkay = doc.LoadFile();
	// faile to load 'phonebookdata.xml'.
	if (!loadOkay) {
		printf("Could not load test file %s. Error='%s'. Exiting.\n", filepath,
				doc.ErrorDesc());
		exit(1);
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

	context_t context(1);
	socket_t s1(context, ZMQ_PULL);
	socket_t s2(context, ZMQ_REP);

	string index_addr = "tcp://";
	index_addr.append(index_ip);
	index_addr.append(":");
	index_addr.append(index_port);

	string search_addr = "tcp://";
	search_addr.append(search_ip);
	search_addr.append(":");
	search_addr.append(search_port);

	s1.bind(index_addr.c_str());
	s2.bind(search_addr.c_str());

	cout << "Starting...." << endl;

	while (1) {
		pollitem_t items[2];
		items[0].socket = s1;
		items[0].fd = 0;
		items[0].events = ZMQ_POLLIN;

		items[1].socket = s2;
		items[1].fd = 0;
		items[1].events = ZMQ_POLLIN;
		int nRet = poll(items, 2);
		if (0 == nRet)
			continue;

		zmq_msg_t msg;

		if (items[0].revents & ZMQ_POLLIN) {
			//index
			cout << "recv index" << endl;
			pthread_t pid;
			message_t request;
			s1.recv(&request);
			char *re_string = new char[request.size()];
			memcpy(re_string, request.data(), request.size());
			int ret = pthread_create(&pid, NULL, index_thread,
					(void*) re_string);
			if (ret < 0) {
				delete[] re_string;
			}
		}

		if (items[1].revents & ZMQ_POLLIN) {
			//search
			string buffer;
			result r;
			search_key t;
			message_t request;

			s2.recv(&request);
			cout<<request.size()<<endl;
			char *re_string = new char[request.size()];
			memcpy((void*)re_string, request.data(), request.size());
			cout<<"lfr"<<re_string<<endl;
			search_msg sm;
			search_result sr;
			if (sm.ParseFromString(re_string)) {
				for (int i = 0; i < sm.word_size(); ++i) {
					t.push_back(sm.word(i));
				}
				index_search::getInstance()->search(t, r);
				search_result sr;
				for (result::const_iterator it = r.begin(); it != r.end();
						++it) {
					sr.add_id(*it);
				}
			} else {
				sr.add_id(-10);
				/*	string buffer;
				 sr.SerializeToString(&buffer);

				 buffer = "lfrdreamman";
				 const char*ii = buffer.c_str();
				 cout << buffer.size() << endl;

				 memcpy(zmq_msg_data(&msg), buffer.c_str(), buffer.size());
				 cout << (char*) zmq_msg_data(&msg) << endl;
				 zmq_msg_send(&msg, s2, 0);
				 */
			}
			sr.SerializeToString(&buffer);
			message_t reply(buffer.size());
			memcpy(reply.data(),buffer.data(), buffer.size());
			s2.send(reply);
			delete[] re_string;
		}
	}
}
