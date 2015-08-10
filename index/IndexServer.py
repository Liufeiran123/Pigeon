__author__ = 'liuqiang'

import zmq
from xml.dom import minidom
from Index import cindex


ci = cindex()

doc = minidom.parse("/Users/liuqiang//PycharmProjects/Pigeon/config/index.xml")
root = doc.documentElement

node = root.getElementsByTagName("index")
ip = node[0].childNodes[1].childNodes[0].nodeValue
port = node[0].childNodes[3].childNodes[0].nodeValue


context = zmq.Context()
#  Socket to talk to server
print("Connecting to hello world server...")
socket = context.socket(zmq.REP)

socketstr = 'tcp://'+ip+':'+port
print socketstr
socket.bind(socketstr)

#  Do 10 requests, waiting each time for a response
while(True):
    print("waiting crawler text")
    #  Get the reply.
    message = socket.recv()

    print("recv text...")
    ci.index(int(message[0]),message[1])

