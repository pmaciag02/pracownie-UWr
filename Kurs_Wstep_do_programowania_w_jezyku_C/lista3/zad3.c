#include <stdio.h>
#define MAX 130


char key[MAX], dkey[MAX];
int inicjalizacja, S, M, L, koniec=0, OK=0;;



void szyfrowanie();
void odszyfrowanie();



int main()
{

    S=32; M=64;
    inicjalizacja=0;
    char polecenie[10];
    int j=0, n;

    while((n=getchar())!=EOF)
    {
        polecenie[j]=n;

    if((polecenie[j])==' ')
    {

    if(polecenie[0]=='C')
    {
        scanf("%d %d", &S, &M);
        getchar();

    }
    else if(polecenie[0]=='K')
    {
        OK=1;
        for(int i=0; i<M; i++)
        {
            key[i]=getchar();
        }
        for(int i=0; i<M; i++)
        {
            dkey[key[i]-S]=i+S;
        }
        getchar();
    }
    else if(polecenie[0]=='I')
    {
        scanf("%d", &inicjalizacja);
        getchar();
    }
    else if(polecenie[0]=='E')
    {
        szyfrowanie();
        if(OK==0) return 0;
    }
    else if(polecenie[0]=='D')
    {
        odszyfrowanie();
        if(OK==0) return 0;
    }


    j=-1;
    }
    j++;
    }


    return 0;
}





void szyfrowanie()
{
    int n;
    //while((n=getchar())>=S && (n=getchar())<=M)
    char t[130];
    int i=0;
    n=getchar();
   // printf("%d", key[(n-S+inicjalizacja)%M]);
   t[i]=key[(n-S+inicjalizacja)%M];
   i++;

    int ostatni = key[(n-S+inicjalizacja)%M]-S;

    while((n=getchar())!='\n')
    {
        if(OK)
        {
        if(n<=S && n>=(M+S)) //ROWNE?
        {
            koniec=1;
        }

        //printf("%d", key[(n-S+ostatni)%M]);
        t[i]=key[(n-S+ostatni)%M];
        ostatni = key[(n-S+ostatni)%M]-S;

        i++;
        }
    }
   // i--;
   if(OK) printf("%.*s\n", i, t);
}







void odszyfrowanie()
{
    int n, x;
    char t[130];
    int i=0;

    n=getchar();
    x=(n-S-inicjalizacja)%M;
    if(((n-S-inicjalizacja)%M)<0) x=M+((n-S-inicjalizacja)%M);
    //printf("%d", dkey[x]);
    t[i]=dkey[x];
    i++;
    int ostatni = n-S;

    while((n=getchar())!='\n')
    {
        if(OK)
        {
        if(n<=S && n>=(M+S))
        {
            koniec=1;
        }

        x=(dkey[n-S]-S-ostatni)%M;
        if(((dkey[n-S]-S-ostatni)%M)<0) x=M+((dkey[n-S]-S-ostatni)%M);
        //printf("%d", x+S);
        
        t[i]=x+S;
        ostatni = n-S;
        i++;
        }
    }
   // i--;
   if(OK) printf("%.*s\n", i, t);
}

