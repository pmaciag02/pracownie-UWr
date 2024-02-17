
#include <stdlib.h>
#include <limits.h>

//Patryk Maciąg 331542 zad.1 lista4

typedef long long int Ulamek;
typedef long long int ll;

Ulamek nowyUlamek(ll a, ll b);
ll licznik(Ulamek x);
ll mianownik(Ulamek x);
ll NWD(ll a, ll b);
Ulamek czytaj();
Ulamek dodawanie(Ulamek a, Ulamek b);
Ulamek odejmowanie(Ulamek a, Ulamek b);
Ulamek mnozenie(Ulamek a, Ulamek b);
Ulamek dzielenie(Ulamek a, Ulamek b);
void wypisz(Ulamek x);
