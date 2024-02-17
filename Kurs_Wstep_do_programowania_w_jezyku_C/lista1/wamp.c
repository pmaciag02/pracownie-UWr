#include <stdio.h>
#include <math.h>

//Patryk Maciąg zad.2. lista 1


int cyfry[10];


int sprawdz(int a, int b)
{
    if((!a%10)&&(!b%10)) return 0;


    int ile_cyfr_a=0, ile_cyfr_b=0, cyfry_ab[10], aa=a, bb=b;

    for(int i=0; i<10; i++){
    cyfry_ab[i]=0;
    }

    while(aa!=0){
        cyfry_ab[aa%10]++;
        ile_cyfr_a++;
        aa/=10;
    }
    while(bb!=0){
        cyfry_ab[bb%10]++;
        ile_cyfr_b++;
        bb/=10;
    }

    if((ile_cyfr_a!=ile_cyfr_b)) return 0;

    for(int i=0; i<10; i++){
        if(cyfry_ab[i]!=cyfry[i]) return 0;
    }


    return 1;
}



int main(void)
{
long long int liczba, liczba2, wynik;
int ok=0;
scanf("%lld",&liczba);
liczba++;
for(long long int w=liczba; w<100000000; w++)
{
int ile_cyfr=0;
ok=0;
for(int i=0; i<10; i++){
    cyfry[i]=0;
}
long long ww=w;
while(ww!=0)
{
    cyfry[ww%10]++;
    ile_cyfr++;
    ww/=10;
}
if(!ile_cyfr%2)
{
    continue;
}
for(int i=1; i*i<=w; i++){
    if(w%i) continue;
    if((!i%10)&&(!(w/i)%10)) continue;
    if(sprawdz(i,w/i)==1)
    {
        liczba2=w;
        wynik=i;
        ok=1;
        break;
    }
}
if(ok)break;
}
if(ok) printf("%lld %lld %lld",liczba2,wynik,liczba2/wynik) ;
else printf("BRAK WAMPIRZEJ\n");
return 0;
}