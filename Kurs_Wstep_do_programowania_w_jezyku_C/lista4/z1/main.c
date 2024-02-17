#include <stdio.h>
#include <stdlib.h>
#include "Ulamek.h"


//Patryk Maciąg 331542 zad.1 lista4

int main()
{
printf("Podaj 1. ułamek wpostaci n/m:\n");
Ulamek u=czytaj();
printf("Test wypisania: ");
wypisz(u);

printf("Podaj 2. ułamek wpostaci n/m:\n");
Ulamek v=czytaj();

printf("Suma: ");
Ulamek z=dodawanie(u,v);
wypisz(z);

printf("Różnica: ");
z=odejmowanie(u,v);
wypisz(z);


printf("Iloczyn: ");
z=mnozenie(u,v);
wypisz(z);


printf("Iloraz: ");
z=dzielenie(u,v);
wypisz(z);


    return 0;
}
