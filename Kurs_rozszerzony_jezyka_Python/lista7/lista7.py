import re
import urllib.request
import threading



def search(url, word):
    with urllib.request.urlopen(url) as f:
        tekst = f.read().decode('utf-8')
    return tekst.count(word)



    

def only1(list1):
    l = []
    for x in list1:
        if x not in l:
            l.append(x)
    return l




def search_word(url, distance, action, sums, word):
    adres = '([a-zA-Z]+.)*[a-zA-Z]+'
    automat = re.compile('<a\shref=\"https?://' + adres)
    with urllib.request.urlopen(url) as f:
        tekst = f.read().decode('utf-8')

    l = [ url.group() for url in automat.finditer(tekst) ]
    t = action(url, word)
    sums.append(t)
    print(f"{url}: {t}")

    if distance == 0:
        return

    links = []
    for link in l:
        links.extend(re.findall(r"http.*[^\.svg]*", link))

    links2 = only1(links)
    for link in links2:
        if not link in sums:
            # if threading.active_count == 6:
            #     threading.current_thread().join()
            t = threading.Thread(target=search_word, args=[link, distance - 1, action, sums, word])
            t.start()
    




def crawl(start_page, distance, action):
    count = 0
    sums = []

    t = threading.Thread(target=search_word, args=[start_page, distance, action, sums, "Python"])
    t.start()
    while len(threading.enumerate()) > 1:
        pass

    for s in sums:
        count += s

    return count



print(crawl("http://www.ii.uni.wroc.pl", 1, search))

