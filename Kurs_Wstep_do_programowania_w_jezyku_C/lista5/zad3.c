#include <stdlib.h>
#include <stdio.h>


int n, B=-1, L=-1, N=-1, M, x=0;


int potega(int B, int L)
{
    int x=B;
    for(int i=2; i<=L; i++)
    {
        x*=B;
    }
    return x;
}


void czytaj()
{
    while((n=getchar())!=EOF)
    {
        if(n=='\n')break;
        if(n==' ')
        {
            if(B==-1)
            {
                B=x;
                x=0;
            }
            else if(L==-1)
            {
                L=x;
                x=0;
            }
            
        }
        else
        {
            x*=10;
            x+=(n-48);
        }
        //printf("%d\n", x);
    }
    

    if(L==-1)
    {
        L=x;
        x=0;
    }
        (x)?(N=x):(N=potega(B,L));
        M=potega(B,L);
}


int f(int a)
{
    a%=M;
    int licznik=0, x=0;
    while(a>0)
    {
        x*=B;
        x+=(a%B);
        a/=B;
        licznik++;
    }
    //printf("%d\n", x);
    for(int i=licznik; i<L; i++)
    {
        x*=B;
    }
    return x;
}


void wypisz(int a)
{
    a%=N;

    for(int i=0; i<N; i++)
    {
        (i==a)?(putchar('X')):(putchar('.'));
    }
    putchar('\n');
}



int main()
{

czytaj();

//printf("%d %d %d %d\n", B, L, N, M);


for(int i=0; i<N; i++)
{
    int w=f(i);

    //printf("%d\n", w);

    wypisz(w);
}

putchar('\n');

for(int i=0; i<N; i++)
{
    int w=rand();

    //printf("%d\n", w);

    wypisz(w);
}
    return 0;
}
