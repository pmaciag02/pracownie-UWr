#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Funkcje.h"

//Patryk Maciąg, 331542, lista 6, zad2


//dla testów p=100 i n=50000 czeka się ok. 7 minut


void czas(clock_t *c, clock_t *czas_min, clock_t *czas_max)
{
if(*c>*czas_max) *czas_max=*c;

if(*c<*czas_min) *czas_min=*c;

}





int main()
{
int p, n;
Tab tab={0}, kopia={0}, kopia2={0};
clock_t czas_min_1=100000, czas_max_1=0, czas_sr_1, suma1=0, czas_min_2=100000, czas_max_2=0, czas_sr_2, suma2=0, czas_min_3=100000, czas_max_3=0, czas_sr_3, suma3=0;


for(int q=1; 1<=3; q++)
{
p=100;
if(q==1)
{
printf("Testy dla tablic o rozmiarze 5000:\n");
n=5000;
}
else if(q==2)
{
printf("Testy dla tablic o rozmiarze 10000:\n");
n=10000;
}
else
{
printf("Testy dla tablic o rozmiarze 50000:\n");
n=50000;
}

czas_min_1=100000; czas_max_1=0; suma1=0; czas_min_2=100000; czas_max_2=0; suma2=0; czas_min_3=100000; czas_max_3=0; suma3=0;

while(p--)
{
generuj(n, &tab);

for(int i=0; i<n; i++)
{
kopia[i]=tab[i];
kopia2[i]=tab[i];
}

//wypisz(n, &tab);


//putchar('\n');

clock_t a=clock();
clock_t c1=select_sort(n, &tab)-a;
clock_t c2=insertion_sort(n, &kopia)-c1-a;
clock_t c3=q_sort(n, &kopia2)-c2-c1-a;

//printf("%ld %ld %ld\n", c1, c2, c3);


czas(&c1, &czas_min_1, &czas_max_1);
czas(&c2, &czas_min_2, &czas_max_2);
czas(&c3, &czas_min_3, &czas_max_3);

//wypisz(n, &tab);
//wypisz(n, &kopia);
//wypisz(n, &kopia2);


suma1+=c1;
suma2+=c2;
suma3+=c3;


}
czas_sr_1=suma1/100;
czas_sr_2=suma2/100;
czas_sr_3=suma3/100;

printf("Minimalny czas sortowania przez selekcje w jednostkach funkcji clock(): %ld\nMaksymalny czas sortowania przez selekcje w jednostkach funkcji clock(): %ld\nŚredni czas sortowania przez selekcje w jednostkach funkcji clock(): %ld\n", czas_min_1, czas_max_1, czas_sr_1);
putchar('\n');

printf("Minimalny czas sortowania przez wstawianie w jednostkach funkcji clock(): %ld\nMaksymalny czas sortowania przez wstawianie w jednostkach funkcji clock(): %ld\nŚredni czas sortowania przez wstawianie w jednostkach funkcji clock(): %ld\n", czas_min_2, czas_max_2, czas_sr_2);
putchar('\n');

printf("Minimalny czas sortowania qsort w jednostkach funkcji clock(): %ld\nMaksymalny czas sortowania qsort w jednostkach funkcji clock(): %ld\nŚredni czas sortowania qsort w jednostkach funkcji clock(): %ld\n", czas_min_3, czas_max_3, czas_sr_3);
putchar('\n');

}



    return 0;
}
