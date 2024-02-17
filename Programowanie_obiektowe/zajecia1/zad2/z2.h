#include <stdlib.h>
#include <stdio.h>


//Patryk Maciąg, 331542, zadanie 2


typedef struct ulamek{
int licznik;
int mianownik;
}Ulamek;

Ulamek * nowy_ulamek(int num, int denom);
void show(Ulamek *u);
Ulamek * dodawanie(Ulamek *u, Ulamek *v);
void dodawanie2(Ulamek *u, Ulamek *v);
Ulamek * odejmowanie(Ulamek *u, Ulamek *v);
void odejmowanie2(Ulamek *u, Ulamek *v);
Ulamek * mnozenie(Ulamek *u, Ulamek *v);
void mnozenie2(Ulamek *u, Ulamek *v);
Ulamek * dzielenie(Ulamek *u, Ulamek *v);
void dzielenie2(Ulamek *u, Ulamek *v);

