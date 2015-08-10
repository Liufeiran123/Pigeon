__author__ = 'liuqiang'

from twisted.enterprise import adbapi
import MySQLdb
import MySQLdb.cursors

dbpool = adbapi.ConnectionPool('MySQLdb',
            db = 'crawler',
            user = 'root',
            passwd = '123',
            cursorclass = MySQLdb.cursors.DictCursor,
            charset = 'utf8',
            use_unicode = False
        )

def _conditional_insert(self, tx, c):
    a = "SELECT url from data where id in("
    for i in c:
        a+=str(i)
        a+=","
    a = a[:-1]
    a+=')'
    return tx.execute(a)


def GetURL(c):
    return dbpool.runInteraction(_conditional_insert, c)
