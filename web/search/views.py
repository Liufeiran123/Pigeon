from django.shortcuts import render,render_to_response
from SearchClient import SearchResult
from QueryData import GetURL
import search_msg_pb2
from mmseg.search import seg_txt_2_dict
from forms import SearchForm
import jieba
import sys
sys.path.append("..")

from util.processword import *

def search(request):
    #form = SearchForm(request.GET)
    search_word = request.GET['a']
    messages_obj = search_msg_pb2.search_msg()
    seg_list = jieba.cut_for_search(search_word)
    wordlist = []
    for word in seg_list:
        wordlist.append(word)
        wordlist = list(set(wordlist))
    print wordlist
    for word in wordlist:#seg_txt_2_dict(search_word).iteritems():
        if not WordIsRight(word):
            continue
        messages_obj.word.append(word.encode('UTF-8'))
    messages_obj_str = messages_obj.SerializeToString()

    messages_obj1 = search_msg_pb2.search_msg()

    messages_obj1.ParseFromString(messages_obj_str)


    idset_str = SearchResult(messages_obj_str)

    print len(idset_str)

    result_obj = search_msg_pb2.search_result()

    result_obj.ParseFromString(idset_str)

    print result_obj.id

    urlset = GetURL(result_obj.id)
    if len(urlset) == 0:
        form = SearchForm()
        return render(request, 'index.html',{'form':form})
    return render_to_response("searchresult.html",{'resultset': urlset})
    #return HttpResponse(a)
#  if request.method == 'POST':
#    form = AddForm(request.POST)

#    if form.is_valid():
     #a = request.GET['a']
    #  b = SearchResult(a)
    #  c = GetURL(b)
    #return HttpResponse(a)
  #else:
    #form = AddForm()

  #return render(request, 'index.html', {'form': form})
def index(request):
    form = SearchForm()
    return render(request, 'index.html',{'form':form})



#def add(request):
#    a = request.GET['a']
#    b = request.GET['b']
#    a = int(a)
#    b = int(b)
#    return HttpResponse(str(a+b))

