__author__ = 'liuqiang'
import re,codecs

def loadstopword():
    x = []
    output = codecs.open("/Users/liuqiang/PycharmProjects/Pigeon/stopword/stopwords.txt",'r','UTF-8')
    for line in output.readlines():
        line = line.strip('\n')
        x.append(line)
    return x

re_filter = re.compile(u"[\u4E00-\u9FA5a-zA-Z]+|[0-9]{2,}")
stopword_list = loadstopword()

def WordIsRight(word):
    if not word:
        return False
    if not re_filter.match(word):
        return False
    if word in stopword_list:
        return False
    return True