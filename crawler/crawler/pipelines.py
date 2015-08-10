# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html
from twisted.enterprise import adbapi
import MySQLdb
import MySQLdb.cursors
from IndexClient import SendText
from TextExtractor import TextExtractor

class CrawlerPipeline(object):
    def __init__(self):
        self.dbpool = adbapi.ConnectionPool('MySQLdb',
            db = 'crawler',
            user = 'root',
            passwd = '123',
            cursorclass = MySQLdb.cursors.DictCursor,
            charset = 'utf8',
            use_unicode = False
        )
        self.textextractor = TextExtractor()
    def process_item(self, item, spider):
        #index
        message = []
        message[0] = self.dbpool.runInteraction(self._conditional_insert, item)
        message[1] = item['text']
        SendText(message)
        return item

    def _conditional_insert(self, tx, item):
        tx.execute('insert into data(url,title,body,text) values (%s, %s, %s, %s)', (item['url'], item['title'], item['body'],item['text']))
        return tx.execute("SELECT max(id) from data")
