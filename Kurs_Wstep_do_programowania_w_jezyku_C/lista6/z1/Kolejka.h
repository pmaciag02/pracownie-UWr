#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct kolejka *KolWsk;

KolWsk inicjuj(int rozmiar);
double pobierz(KolWsk K);
bool dopisz(KolWsk K, double x);
bool wyczysc(KolWsk K);
bool pusta(KolWsk K);
