#include <stdlib.h>
#include <stdio.h>
#include "z2.h"

//Patryk Maciąg, 331542, zadanie 2



int NWD(int a, int b)
{
int c;

while(b!=0)
{
c=b;
b=a%b;
a=c;
}

return a;
}

int NWW(int a, int b)
{
    return (a/NWD(a,b))*b;
}

Ulamek * nowy_ulamek(int num, int denom)
{
    Ulamek *n = malloc(sizeof(Ulamek));


    int k=NWD(abs(num), abs(denom));
    num/=k; denom/=k;

    if(num>0 && denom>0)
    {
        n->licznik=num;
        n->mianownik=denom;
    }
    else if(num<0 && denom<0)
    {
        n->licznik=-num;
        n->mianownik=denom*(-1);
    }
    else if(num<0)
    {
        n->licznik=num;
        n->mianownik=denom;
    }
    else
    {
        n->licznik=num*(-1);
        n->mianownik=denom*(-1);
    }


    return n;
}

void show(Ulamek *u)
{
    printf("%d/%d\n", u->licznik, u->mianownik);
}


Ulamek * dodawanie(Ulamek *u, Ulamek *v)
{
    Ulamek *n = malloc(sizeof(Ulamek));

    int k = NWW(u->mianownik, v->mianownik);
    n->mianownik=k;
    n->licznik=u->licznik*(k/u->mianownik) + v->licznik*(k/v->mianownik);
    return n;
}


void dodawanie2(Ulamek *u, Ulamek *v)
{
    int k = NWW(u->mianownik, v->mianownik);
    v->mianownik=k;
    v->licznik=u->licznik*(k/u->mianownik) + v->licznik*(k/v->mianownik);
}

Ulamek * odejmowanie(Ulamek *u, Ulamek *v)
{
    Ulamek *n = malloc(sizeof(Ulamek));

    int k = NWW(u->mianownik, v->mianownik);
    n->mianownik=k;
    n->licznik=u->licznik*(k/u->mianownik) - v->licznik*(k/v->mianownik);
    return n;
}


void odejmowanie2(Ulamek *u, Ulamek *v)
{
    int k = NWW(u->mianownik, v->mianownik);
    v->mianownik=k;
    v->licznik=u->licznik*(k/u->mianownik) - v->licznik*(k/v->mianownik);
}


Ulamek * mnozenie(Ulamek *u, Ulamek *v)
{
    Ulamek *n = malloc(sizeof(Ulamek));

    int a = u->licznik * v->licznik;
    int b = u->mianownik * v->mianownik;

    int k=NWD(abs(a), abs(b));
    a/=k; b/=k;

    n->licznik=a;
    n->mianownik=b;
    return n;
}


void mnozenie2(Ulamek *u, Ulamek *v)
{

    int a = u->licznik * v->licznik;
    int b = u->mianownik * v->mianownik;

    int k=NWD(abs(a), abs(b));
    a/=k; b/=k;

    v->licznik=a;
    v->mianownik=b;
}

Ulamek * dzielenie(Ulamek *u, Ulamek *v)
{
    Ulamek *n = malloc(sizeof(Ulamek));

    int a = u->licznik * v->mianownik;
    int b = u->mianownik * v->licznik;

    int k=NWD(abs(a), abs(b));
    a/=k; b/=k;



    if(a>0 && b>0)
    {
        n->licznik=a;
        n->mianownik=b;
    }
    else if(a<0 && b<0)
    {
        n->licznik=-a;
        n->mianownik=b*(-1);
    }
    else if(a<0)
    {
        n->licznik=a;
        n->mianownik=b;
    }
    else
    {
        n->licznik=a*(-1);
        n->mianownik=b*(-1);
    }

    return n;
}


void dzielenie2(Ulamek *u, Ulamek *v)
{
    int a = u->licznik * v->mianownik;
    int b = u->mianownik * v->licznik;

    int k=NWD(abs(a), abs(b));
    a/=k; b/=k;



    if(a>0 && b>0)
    {
        v->licznik=a;
        v->mianownik=b;
    }
    else if(a<0 && b<0)
    {
        v->licznik=-a;
        v->mianownik=b*(-1);
    }
    else if(a<0)
    {
        v->licznik=a;
        v->mianownik=b;
    }
    else
    {
        v->licznik=a*(-1);
        v->mianownik=b*(-1);
    }
}
