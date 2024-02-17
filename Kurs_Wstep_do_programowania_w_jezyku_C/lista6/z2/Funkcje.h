#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef double Tab[50005];


void generuj(int n, Tab *tab);
void wypisz(int n, Tab *tab);
clock_t select_sort(int n, Tab *tab);
clock_t insertion_sort(int n, Tab *tab);
clock_t q_sort(int n, Tab *tab);
