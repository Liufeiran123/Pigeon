from django.shortcuts import render,render_to_response
from django.http import HttpResponse

# Create your views here.

from SearchClient import SearchResult
from QueryData import GetURL

def search(request):
    a = request.GET['wd']
    b = SearchResult(a)
    c = GetURL(b)
    if len(a) == 0:
        return render(request, 'index1.html')
    return render_to_response("searchresult.html",{'resultset': c})
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
  return render(request, 'index1.html')



#def add(request):
#    a = request.GET['a']
#    b = request.GET['b']
#    a = int(a)
#    b = int(b)
#    return HttpResponse(str(a+b))

