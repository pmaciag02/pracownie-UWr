#z2

def pierwiastek(n):
    x = 0
    for i in range(1, n+1):
        x += (2*i) - 1
        if x > n:
            return i-1


print(pierwiastek(4))
print(pierwiastek(10))


#z4

from os import remove
import random


def uprosc_zdanie(tekst, dl_slowa, liczba_slow):

    t = tekst.split(' ')
    
    t = list(filter(lambda l: len(l) > 0, t))

    for x in t:
        if len(x) > dl_slowa or len(x) == 0:
            t.remove(x)


    while len(t) > liczba_slow:
        rand = random.randint(0, len(t)-1)
        t.remove(t[rand])

    return ' '.join(t)


tekst = "Podział peryklinalny inicjałów wrzecionowatych \
        kambium charakteryzuje się ścianą podziałową inicjowaną \
        w płaszczyźnie maksymalnej."

print(uprosc_zdanie(tekst, 10, 5))



#z5

def kompresja(tekst):
    tmp = tekst[0]
    count = 1
    komp = list()
    for char in tekst[1:]:
        if char == tmp:
            count += 1
        elif count > 1:
            komp.append((count, tmp))
            count = 1
        else:
            komp.append((1, tmp))
        tmp = char
    if count > 1:
        komp.append((count, tmp))
    else:
        komp.append((1, tmp))
    return komp



def dekompresja(tekst_skompresowany):
    tekst = ""
    for i in tekst_skompresowany:
        if i[0] > 1:
            for _ in range(i[0]):
                tekst += i[1]
        else:
            tekst += i[1]
    return tekst


print(kompresja("suuuuper"))
print(kompresja("aaaaa"))

print(dekompresja([(1, 's'), (4, 'u'), (1, 'p'), (1, 'e'), (1, 'r')]))
print(dekompresja([(5, 'a')]))