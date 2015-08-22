__author__ = 'liuqiang'


import zmq
from xml.dom import minidom

doc = minidom.parse("/Users/liuqiang//PycharmProjects/Pigeon/config/crawler.xml")
root = doc.documentElement

node = root.getElementsByTagName("index")
ip = node[0].childNodes[1].childNodes[0].nodeValue
port = node[0].childNodes[3].childNodes[0].nodeValue

socketstr = 'tcp://'+ip+':'+port

context = zmq.Context()
socket = context.socket(zmq.PUSH)

socket.connect(socketstr)

def SendText(message):
    socket.send(message)
