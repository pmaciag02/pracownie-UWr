#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Funkcje.h"




void generuj(int n, Tab *tab)
{

for(int i=0; i<n; i++)
{
(*tab)[i]=rand();
}

}

void wypisz(int n, Tab *tab)
{
for(int i=0; i<n; i++)
{
printf("%.f ", (*tab)[i]);
}
putchar('\n');
}




clock_t select_sort(int n, Tab *tab)
{
int min_i;

    for(int i=0; i<n-1; i++)
    {
        min_i=i;
        for(int j=i+1; j<n; j++)
        {
          if((*tab)[j]<(*tab)[min_i]) min_i=j;
        }

        double a=(*tab)[i];
        (*tab)[i]=(*tab)[min_i];
        (*tab)[min_i]=a;

    }
    return clock();
}

clock_t insertion_sort(int n, Tab *tab)
{
int k, j;
    for(int i=1; i<n; i++)
    {
        k=(*tab)[i];
        j=i-1;

        while(j>=0 && (*tab)[j]>k)
        {
            (*tab)[j+1]=(*tab)[j];
            j--;
        }
        (*tab)[j+1]=k;
    }
    return clock();
}



int comp(const void *a, const void *b)
{
const double *pa=a;
const double *pb=b;
if(*pa>*pb) return 1;
else return 0;
}

clock_t q_sort(int n, Tab *tab)
{
qsort(tab, n, sizeof(double), comp);

return clock();
}



