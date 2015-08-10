__author__ = 'liuqiang'


import xapian
from mmseg.search import seg_txt_2_dict
from xml.dom import minidom

class IndexSearch():
    def __init__(self):
        doc = minidom.parse("//Users/liuqiang//PycharmProjects/Pigeon/config/search.xml")
        root = doc.documentElement
        node = root.getElementsByTagName("indexdb")

        self.db = xapian.WritableDatabase(node[0].childNodes[0].nodeValue, xapian.DB_OPEN)
        self.enquire = xapian.Enquire(self.db)
        self.enquire.set_sort_by_value(1, True)

    def get_document(self, id):
        return self.db.get_document(id)

    def search(self, keywords, offset=0, limit=10):
        query_list = []
        for word, value in seg_txt_2_dict(keywords).iteritems():
            query = xapian.Query(word)
            query_list.append(query)

        if len(query_list) != 1:
            query = xapian.Query(xapian.Query.OP_AND, query_list)
        else:
            query = query_list[0]

        self.enquire.set_query(query)
        matches = self.enquire.get_mset(offset, limit, 10000)
        return matches
