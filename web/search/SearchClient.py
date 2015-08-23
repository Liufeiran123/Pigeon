__author__ = 'liuqiang'

import zmq
from xml.dom import minidom

doc = minidom.parse("//Users/liuqiang/PycharmProjects/Pigeon/config/web.xml")
root = doc.documentElement

node = root.getElementsByTagName("search")
ip = node[0].childNodes[1].childNodes[0].nodeValue
port = node[0].childNodes[3].childNodes[0].nodeValue

context = zmq.Context()
#  Socket to talk to server
socket = context.socket(zmq.REQ)
socketstr = 'tcp://'+ip+':'+port
socket.connect(socketstr)

def SearchResult(keyword):
    socket.send(keyword)
    return socket.recv()