#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Kolejka.h"


typedef struct kolejka
{
    double *tab;
    int rozmiar;
    int ile_elem;
    double *pocz, *kon;
}Kolejka;


KolWsk inicjuj(int rozmiar)
{
    Kolejka *kol=calloc(rozmiar, sizeof(double));

    kol->tab=malloc(rozmiar*sizeof(double));
    kol->rozmiar=rozmiar;
    kol->ile_elem=0;
    kol->pocz=kol->tab;
    kol->kon=kol->tab;

    return kol;
}


 bool dopisz(KolWsk K, double x)
 {
     if((K->kon)==((K->tab)+(K->rozmiar)))
     {

     if((K->pocz)==K->tab){

     double ile=(K->rozmiar)*2;


         double *nowe_tab;

         nowe_tab=realloc(K->tab, sizeof(double)*ile);
         K->tab=nowe_tab;

         K->rozmiar*=2;
         *K->kon=x;
         K->kon++;
         }
         else
         {

         K->tab[0]=x;
         K->kon=K->tab;
         K->kon++;


         if(pusta(K))
         {

         double ile=(K->rozmiar)*2;
         int np;
         for(int i=0; i<K->rozmiar; i++)
         {
         if(K->pocz==(K->tab+i))
         {
         np=i;
         }
         }
         double *nowe_tab;

         nowe_tab=realloc(K->tab, sizeof(double)*ile);
         K->tab=nowe_tab;

         (K->rozmiar)*=2;

         K->kon=(K->tab)+((K->rozmiar)/2);
         K->pocz=(K->tab)+np;


         for(int i=0; i<(K->rozmiar)/2; i++)
         {
         if(((K->tab)+i)==(K->pocz)) break;

         double *u=K->tab+((K->rozmiar)/2)+i;
         *u=*(K->tab+i);
         }
         }
         }
     }
     else
     {

         *K->kon=x;
         K->kon++;
         if(pusta(K))
         {


         double ile=(K->rozmiar)*2;
         int np;
         for(int i=0; i<K->rozmiar; i++)
         {
         if(K->pocz==(K->tab+i))
         {
         np=i;
         }

         }

         double *nowe_tab;

         nowe_tab=realloc(K->tab, sizeof(double)*ile);
         K->tab=nowe_tab;

         (K->rozmiar)*=2;
         K->kon=(K->tab)+((K->rozmiar)/2);

         K->kon=(K->tab)+((K->rozmiar)/2);
         K->pocz=(K->tab)+np;


         for(int i=0; i<(K->rozmiar)/2; i++)
         {
         if(((K->tab)+i)==(K->pocz)) break;

         double *u=K->tab+((K->rozmiar)/2)+i;
         *u=*(K->tab+i);
         }
         }
     }
     return 1;
 }




 double pobierz(KolWsk K)
 {

     double wynik=*K->pocz;

     K->pocz++;
     if((K->pocz)==((K->tab)+(K->rozmiar)))
     {
     K->pocz=K->tab;
     }

     return wynik;
 }




 bool wyczysc(KolWsk K)
 {
     K->pocz=K->kon;
     return 1;
 }



bool pusta(KolWsk K)
{
    if((K->pocz)==(K->kon))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
