__author__ = 'liuqiang'
from crawler.crawler import index_msg_pb2

a = index_msg_pb2.index_msg()

a.max_id  = 3
a.text = 'oooo'

b=a.SerializeToString()

c =0