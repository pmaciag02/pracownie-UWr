# Raport do zadania 2

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

(dla hex_seed = 0x1, log2(size) = 5, log2(steps) = 20, log2(times) = 10)

![](https://i.imgur.com/Ff12ZwE.png)


(dla róznych log2(size))
![](https://i.imgur.com/3su9rEq.png)


Wnioski
---

Optymalizacja polega na zamianie instrukcji warunkowych `if` na operator `?` (`a ? b : c`). Dzięki temu unikamy wielu skoków warunkowych.

Korzystając z flagi `-p ipc` uzyskujemy liczbę wszystkich instrukcji (total instructions), jak i średnią liczbę instrukcji na cykl (instructions per cycle).
Dla `randwalk0` całkowita suma to ponad 23000000000 instrukcji (ok. 23186381000), natomiast średnio na cykl wychodzi ok. 0.77 instrukcji.
Dla `randwalk1` całkowita suma to ponad 32000000000 instrukcji (ok. 32648588000), natomiast średnio na cykl wychodzi ok. 1.6 instrukcji.
(wyniki powstały dla podanych nad wykresem danych)


Kolejność instrukcji w ciele pętli również trochę wpływa na IPC.
Jeśli pozostwnimy instrukcje warunkowe w kolejności rosnącego lub malejącego sprawdzania wartości "d", to otrzymamy największe IPC. Dla losowej kolejności wynik jest mniejszy. Największa róznica jaką zaobsewowałem wynosiła ok. 0.2 instrukcji.

Drugi wygres pokazuje, że rozmiar tablicy nie ma zbyt dużego wpływu na czas wykonania programu. Różnice są niewielkie.



