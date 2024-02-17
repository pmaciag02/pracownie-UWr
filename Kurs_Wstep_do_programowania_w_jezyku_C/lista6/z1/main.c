#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Kolejka.h"

//Patryk Maciąg, 331542, lista 6, zad 1

//słaba wersja kodu

//polecenia dla kolejki:
//wpisz 1, wypisz, wpisz 2, wypisz, wpisz 3, 4, 5, 6, wypisz, wypisz, wypisz, wypisz, sprawdz czy pusta, dopisz 6, wyczysc, sprawdz czy pusta




int main()
{
int r=4;
double x=1;
    KolWsk k=inicjuj(r);
    dopisz(k,x);
    double wynik=pobierz(k);
    printf("%f\n", wynik);
    x=2;
    dopisz(k,x);
    wynik=pobierz(k);
    printf("%f\n", wynik);
    x=3;
    dopisz(k,x);
    x=4;
    dopisz(k,x);
    x=5;
    dopisz(k,x);
    dopisz(k,x);
    dopisz(k,x);


    wynik=pobierz(k);
    printf("%f\n", wynik);
    wynik=pobierz(k);
    printf("%f\n", wynik);
    wynik=pobierz(k);
    printf("%f\n", wynik);
    wynik=pobierz(k);
    printf("%f\n", wynik);

    (pusta(k))?(printf("Kolejka jest pusta.\n")):(printf("Kolejka nie jest pusta.\n"));
    dopisz(k,x);
    wyczysc(k);
    (pusta(k))?(printf("Kolejka jest pusta.\n")):(printf("Kolejka nie jest pusta.\n"));
    return 0;
}
