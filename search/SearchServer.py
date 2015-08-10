__author__ = 'liuqiang'


import zmq
from xml.dom import minidom
from Search import IndexSearch

doc = minidom.parse("/Users/liuqiang//PycharmProjects/Pigeon/config/search.xml")
root = doc.documentElement

node = root.getElementsByTagName("search")
ip = node[0].childNodes[1].childNodes[0].nodeValue
port = node[0].childNodes[3].childNodes[0].nodeValue

socketstr = 'tcp://'+ip+':'+port

context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind(socketstr)

ins = IndexSearch()

while True:
    # Wait for next request from client
    print "Waiting request:"
    message = socket.recv()
    # Send reply back to client
    matches = ins.search(message)
    result = []
    for m in matches:
        result.append(m.docid)
    socket.send(result)
