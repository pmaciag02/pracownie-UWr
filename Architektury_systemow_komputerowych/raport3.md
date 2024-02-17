# Raport do zadania 3

### Autor: Patryk Maciąg
### Numer indeksu: 331542

Konfiguracja
---

Informacje o systemie:

 * Dystrybucja: Ubuntu 20.04.4 LTS x86_64
 * Jądro systemu: 5.4.0-113-generic
 * Kompilator: gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 * Procesor: Intel(R) Core(TM) i5-8265U CPU @ 1.60GHz
 * Liczba rdzeni: 4

Pamięć podręczna:

 * L1d: 32 KiB, 8-drożny (per rdzeń), rozmiar linii 64B
 * L2: 256 KiB, 4-drożny (per rdzeń), rozmiar linii 64B
 * L3: 6 , 12-drożny (współdzielony), rozmiar linii 64B

Pamięć TLB:

 * L1d: 4KiB strony, 4-drożny, 64 wpisy
 * L2: 4KiB strony, 6-drożny, 1536 wpisów

Informacje o pamięciach podręcznych uzyskano na podstawie wydruku programu
`x86info` oraz opisu procesora na stronach internetowych (nie wszystkie informacje były w x86info).

Wyniki eksperymentów
---

Przykładowy wykres przedstawiający uśrednione pomiary:


(po wywołaniu ./binsearch -S 0x5bab3de5da7882ff -n 23 -t 24 -v 0/1; dane z GNUmakefile)
![](https://i.imgur.com/rF1CBp6.png)

(po wywołaniu ./binsearch -S 0x5bab3de5da7882ff -n 23 -t 24 -v 1 -p ipc; dane z GNUmakefile)
![](https://i.imgur.com/fNV9sgw.png)



Wnioski
---

Zmiana organizacji danych spowodowała przyśpieszenie algorytmu wyszukiwania, ponieważ dzięki funkcji linearize, dane/kolejne poziomy drzewa będą leżeć blisko siebie. Wprzypadku binsearch0 faktycznie używane dane mogły być bardzo daleko od siebie i nawet mogą nie znajdować się w pamięci cache.

Jeśli chodzi o wpływ kolejności instrukcji na IPC, to najwydajniej działa wersja gdzie warunek `x == y` jest sprawdzany na sam koniec. Na wykresie dla porównania są wyniki pomiarów z wersją, gdzie warunek był na początku pętli.
