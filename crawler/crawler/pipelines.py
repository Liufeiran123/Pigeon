# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html
import codecs
import MySQLdb
import MySQLdb.cursors
from IndexClient import SendText
import index_msg_pb2
from mmseg.search import seg_txt_2_dict
import jieba
import sys
sys.path.append("..")
from util.processword import *


class CrawlerPipeline(object):
    def __init__(self):
        self.db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="123", db="crawler",charset='utf8')
        self.cursor = self.db.cursor()


    def insertitem(self,item):
        try:
            self.cursor.execute('insert into data(url,title,body,text) values (%s, %s, %s, %s)',(item['url'], item['title'], item['body'],item['text']))
            self.db.commit()
        except Exception,e:
            print e
            self.db.rollback()
    def maxid(self):
        sql = "SELECT max(id) FROM data"
        try:
            self.cursor.execute(sql)
            mi = self.cursor.fetchone()

        except Exception,e:
            print e
        return mi[0]

    def process_item(self, item, spider):
        #index
        wordlist =[]
        messages_obj = index_msg_pb2.index_msg()
        self.insertitem(item)
        messages_obj.max_id = self.maxid()
        seg_list = jieba.cut_for_search(item['text'])
        for word in seg_list:
            wordlist.append(word)
        wordlist = list(set(wordlist))

        for word in wordlist:       #seg_txt_2_dict(item['text']).iteritems():
            if not WordIsRight(word):
                continue
            print word
            singitem = messages_obj.single_item.add()
            singitem.item = word.encode('utf-8');
            singitem.num = 1;
        messages_obj_str = messages_obj.SerializeToString()

        SendText(messages_obj_str)
        print 'lfr1'
        return item
