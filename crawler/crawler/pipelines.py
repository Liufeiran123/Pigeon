# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html

import MySQLdb
import MySQLdb.cursors
from IndexClient import SendText

class CrawlerPipeline(object):
    def __init__(self):
        self.db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="123", db="crawler",charset='utf8')
        self.cursor = self.db.cursor()


    def insertitem(self,item):
        try:
            print item['title']
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
            print "Error: unable to fecth data"
        return mi[0]

    def process_item(self, item, spider):
        #index
        message = []
        self.insertitem(item)
        message.append(self.maxid())
        message.append(item['text'])

        print 'lfr'
        SendText(self.message)
        print 'lfr1'
        return item
