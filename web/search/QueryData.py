#coding=utf-8

import MySQLdb
import MySQLdb.cursors



db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="123", db="crawler",charset='utf8')
cursor = db.cursor()

def select1(c):
    a = "SELECT url from data where id in("
    for i in c:
        a+=str(i)
        a+=","
    a = a[:-1]
    a+=')'
    return a

def GetURL(c):
    r = []
    if c[0] == -10:
       return r
    a = select1(c)
    try:
        cursor.execute(a)
        # 获取所有记录列表
        results = cursor.fetchall()
        for row in results:
            r.append(row[0])
    except Exception,e:
        print e
    return r


