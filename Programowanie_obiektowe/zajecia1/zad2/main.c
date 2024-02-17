#include <stdlib.h>
#include <stdio.h>
#include "z2.h"

//Patryk Maciąg, 331542, zadanie 2


int main()
{
    int a, b;
    printf("Podaj licznik i mianownik ulamka nr 1: ");
    scanf("%d %d", &a, &b);
    printf("ułamek nr 1 = ");
    Ulamek *u=nowy_ulamek(a,b);
    show(u);
    printf("Podaj licznik i mianownik ulamka nr 2: ");
    scanf("%d %d", &a, &b);
    printf("ułamek nr 2 = ");
    Ulamek *v=nowy_ulamek(a,b);
    show(v);


    printf("suma = ");
    Ulamek *z=dodawanie(u,v);
    show(z);

    printf("różnica = ");
    z=odejmowanie(u,v);
    show(z);

    printf("iloczyn = ");
    z=mnozenie(u,v);
    show(z);

    printf("iloraz = ");
    z=dzielenie(u,v);
    show(z);


    printf("\nwyniki alternatywnych funkcji:\n");
    dodawanie2(u,v);
    show(v);

    odejmowanie2(u,v);
    show(v);

    mnozenie2(u,v);
    show(v);

    dzielenie2(u,v);
    show(v);

    return 0;
}
