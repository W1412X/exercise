import requests
import re
import bs4
from bs4 import BeautifulSoup
url="https://www.qishuta.org"
print("please enter the name of the book")
book_name=input()
search_url=url+"/search.html?searchkey="+book_name
kv={"user-agent":"Mozilla/5.0"}
r=requests.get(search_url,kv)
r.encoding=r.apparent_encoding
if(r.status_code==200):
    print("Connected")
else:
    print("Disconnected")
#get the search result
def get_search_result(r):
    soup=BeautifulSoup(r.text,"html.parser")
    i=1
    for book in soup.find("table").children:
        if isinstance(book,bs4.element.Tag):
            td_tags=book.find_all('td')
            if(len(td_tags)>=3):
                print(str(i)+" "+td_tags[1].find('a').string+' '+td_tags[2].string)
                i=i+1
    print("choose the order of the book")
    choose=int(input())
    books=soup.find('table').children
    i=0
    for book in books:
        if isinstance(book,bs4.element.Tag):
            if(i==choose):
                found_book=book
                if not book.find('td'):
                    continue
                return [found_book.find_all('td')[1].find('a').string,found_book.find_all('td')[1].find('a').get('href')]
            else:
                i=i+1
book_list=[]
book_list=get_search_result(r)
book_url=url+book_list[1]
r=requests.get(book_url,kv)
r.encoding=r.apparent_encoding
soup=BeautifulSoup(r.text,"html.parser")
def get_dl_po(soup,book_list):
    body=soup.find('body')
    div=body.find_all('div',recursive=False)[3].find_all('div',recursive=False)[1].find_all('div',recursive=False)[2].find_all('div',recursive=False)[1]
    ul=div.find('ul')
    li=ul.find_all('li',recursive=False)
    script=li[2].find('script')
    s=str(script.string)
    pattern=re.compile(r'https?://[\w\-\./:]+txt')
    dl_po=re.findall(pattern,s)[0]
    return dl_po
dl_po=get_dl_po(soup,book_list)
def download(dl_po):
    print("enter the position you want to downloads")
    sv_po=input()
    r=requests.get(dl_po,headers=kv)
    r.encoding=r.apparent_encoding
    pattern=re.compile(r'[\u4e00-\u9fa5]+.txt')
    sv_name=re.findall(pattern,dl_po)[0]
    if(r.status_code==200):
        with open(sv_po+"/"+sv_name,"wb") as f:
            f.write(r.content)
        print("Download!")
download(dl_po)
