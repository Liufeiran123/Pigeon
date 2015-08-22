from django.shortcuts import render,render_to_response
from SearchClient import SearchResult
from QueryData import GetURL
import search_msg_pb2
from mmseg.search import seg_txt_2_dict
from forms import SearchForm

def search(request):
    #form = SearchForm(request.GET)
    search_word = request.GET['a']
    print search_word
    messages_obj = search_msg_pb2.search_msg()
    for word, value in seg_txt_2_dict(search_word).iteritems():
        messages_obj.word.append(word)
    messages_obj_str = messages_obj.SerializeToString()

    idset_str = SearchResult(messages_obj_str)

    result_obj = search_msg_pb2.search_result()
    print 'po33'
    result_obj.ParseFromString(idset_str)
    print '3223'

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

