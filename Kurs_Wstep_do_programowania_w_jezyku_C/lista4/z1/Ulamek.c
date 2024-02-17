
#include <stdio.h>
#include <stdlib.h>
#include "Ulamek.h"

//Patryk Maciąg 331542 zad.1 lista4

ll NWD(ll a, ll b)
{
ll c;

while(b!=0)
{
c=b;
b=a%b;
a=c;
}

return a;
}

Ulamek czytaj()
{
int a,b;
scanf("%d/%d", &a, &b);

return nowyUlamek(a, b);
}

Ulamek nowyUlamek(ll a, ll b)
{
if(b<0)
{
b*=-1;
a*=-1;
}


ll n=0;
if(a<0 && b<0)
{
n=NWD(a*-1,b*-1);
}
else if(a<0)
{
n=NWD(a*-1,b);
}
else if(b<0)
{
n=NWD(a,b*-1);
}
else
{
n=NWD(a,b);
}


//ll n=NWD(a,b);

a/=n; b/=n;



a<<=32;
a|=b;

return a;
}


ll licznik(Ulamek x)
{

ll y=x>>32;

return y;
}

ll mianownik(Ulamek x)
{
ll y=licznik(x)<<32;

ll z=x^y;
return z;
}

Ulamek dodawanie(Ulamek a, Ulamek b)
{
ll la=licznik(a), lb=licznik(b), ma=mianownik(a), mb=mianownik(b);
ll lc=(la*mb)+(lb*ma), mc=ma*mb;

ll n=0;
if(lc<0 && mc<0)
{
n=NWD(lc*-1,mc*-1);
}
else if(lc<0)
{
n=NWD(lc*-1,mc);
}
else if(mc<0)
{
n=NWD(lc,mc*-1);
}
else
{
n=NWD(lc,mc);
}


lc/=n;
mc/=n;


return nowyUlamek(lc,mc);
}

Ulamek odejmowanie(Ulamek a, Ulamek b)
{
ll la=licznik(a), lb=licznik(b), ma=mianownik(a), mb=mianownik(b);
ll lc=(la*mb)-(lb*ma), mc=ma*mb;

ll n=0;
if(lc<0 && mc<0)
{
n=NWD(lc*-1,mc*-1);
}
else if(lc<0)
{
n=NWD(lc*-1,mc);
}
else if(mc<0)
{
n=NWD(lc,mc*-1);
}
else
{
n=NWD(lc,mc);
}


lc/=n;
mc/=n;


return nowyUlamek(lc,mc);
}

Ulamek mnozenie(Ulamek a, Ulamek b)
{
ll la=licznik(a), lb=licznik(b), ma=mianownik(a), mb=mianownik(b);
ll lc=la*lb, mc=ma*mb;

ll n=0;
if(lc<0 && mc<0)
{
n=NWD(lc*-1,mc*-1);
}
else if(lc<0)
{
n=NWD(lc*-1,mc);
}
else if(mc<0)
{
n=NWD(lc,mc*-1);
}
else
{
n=NWD(lc,mc);
}


lc/=n;
mc/=n;


return nowyUlamek(lc,mc);
}

Ulamek dzielenie(Ulamek a, Ulamek b)
{
ll la=licznik(a), lb=licznik(b), ma=mianownik(a), mb=mianownik(b);
ll lc=la*mb, mc=lb*ma;

ll n=0;
if(lc<0 && mc<0)
{
n=NWD(lc*-1,mc*-1);
}
else if(lc<0)
{
n=NWD(lc*-1,mc);
}
else if(mc<0)
{
n=NWD(lc,mc*-1);
}
else
{
n=NWD(lc,mc);
}


lc/=n;
mc/=n;


return nowyUlamek(lc,mc);
}

void wypisz(Ulamek x)
{
printf("%lld/%lld\n", licznik(x), mianownik(x));
}
