# Raport do zadania 1

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

#### Przykładowy wykres przedstawiający uśrednione pomiary:

![](https://i.imgur.com/8uPNzzb.png)



#### Wyniki "make sim":
|| Time Elapsed | Branch misprediction ratio | L1 miss ratio | LL miss ratio |
| ------- | ------------ | -------------------------- | ------------- | ------------- |
| matmult0 |  1.556594 | 0.391% | 50.167% | 50.147% |
| matmult1 |  1.412841 | 0.391% | 6.457%  | 0.404% |
| matmult2 |  1.935733 | 0.391% | 100%    | 100% |
| matmult3 |  1.475724 | 6.250% | 2.086%  | 0.441% |


#### Czas wykonania matmult3 względem rozmiaru kafelka:
![](https://i.imgur.com/r51NLwQ.png)


Wnioski
---

Jeśli chodzi o wyniki symulacji, a wyniki z prezentacji, to są one podobne. Na pewno w obu przypadkach widać tendencje wzrostu wartości czasu, oraz hierarchia wydajności jest ta sama.



Najlepiej działają wersje matmult3 oraz matmult1, ponieważ procesor operuje na bliskich adresach.

Wersje matmult2 oraz matmult4 nie są optymalne, co zauważalnie widać przy macierzach o większym rozmiarze.

Ten wykres to dobry przykład na wagę częstotliwości odwołań do pamięci (im mniej, tym lepiej/szybciej).

Sprawdzając wpływ rozmiaru kafelka na wydajność "matmult3", doszedłem do wniosku, że najlepszy rozmiar z testowanych to 16 (jak widać na załączonym wyżej wykresie). Podczas testu romiar rozmiar macierzy wynosił 1024x1024, tak jak w testach w pliku "GNUmakefile". 
Przy zmniejszaniu kafelka, zmuszamy się do wielokrotnych odwołań do pamięci, natomiast zwiększanie uniemożliwia pobranie go w całości za jednym razem do pamięci podręcznej, co również wydłuża czas.



Natomiast co do spadku wydajności matmult3 po ustawieniu watości A_OFFSET, B_OFFSET oraz C_OFFSET na 0, to szczerze nie zauważyłem zbyt wielkiej róznicy. Np. było nawet szybciej średnio o kilka setnych sekundy dla bloczka o rozmiarze 16.



