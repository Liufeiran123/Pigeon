__author__ = 'liuqiang'

import xapian
from mmseg.search import seg_txt_2_dict
from xml.dom import minidom

class cindex:

    def __init__(self):
        doc = minidom.parse("//Users/liuqiang/PycharmProjects/Pigeon/config/index.xml")
        root = doc.documentElement
        node = root.getElementsByTagName("indexdb")

        self.db = xapian.WritableDatabase(node[0].childNodes[0].nodeValue, xapian.DB_CREATE_OR_OPEN)

    def get_document(self, id):

        return self.db.get_document(id)

    def delete_document(self,id):

        try:
            return self.db.delete_document(id)
        except:
            return None

    def update_index(self, id, text=None, values=None, data=None):
        try:
            doc = self.get_document(id)
        except:
            return False

        if text:
            doc.clear_terms()
            for word, value in seg_txt_2_dict(text).iteritems():
                doc.add_term(word)

        if values:
            doc.clear_values()
            for key, value in values.iteritems():
                doc.add_value(key, value)

        if data:
            doc.set_data(data)

        try:
            self.db.replace_document(id, doc)
            return True
        except:
            return False

    def index(self, id, text, values={}, data=''):
        doc = xapian.Document()
        for word, value in seg_txt_2_dict(text).iteritems():
            print word, value
            doc.add_term(word)

        for key, value in values.iteritems():
            doc.add_value(key, value)

        if data:
            doc.set_data(data)

        try:
            self.db.replace_document(id, doc)
            return True
        except:
            return False

    def flush(self):
        return self.db.flush()
