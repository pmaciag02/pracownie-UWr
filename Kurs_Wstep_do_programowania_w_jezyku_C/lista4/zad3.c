#include <stdio.h>
#include <stdlib.h>

int main()
{

int N;
scanf("%d", &N);


if(N==1)
{
    putchar('#');
    return 0;
}

if(N<1 || N%2==0)
{
    printf("ERROR");
    return 0;
}

int n, startksztalt, ksztalt;

((N/2)%2)?(startksztalt=0):(startksztalt=1);

n=N;
ksztalt=(startksztalt+1)%2;

    putchar('#');
    for(int i=1; i<=(n-2); i++)
    {
        (startksztalt)?(putchar('#')):(putchar('o'));
    }
    
    putchar('#');
    n-=2;
    putchar('\n');

while(n>1)
{
    for(int i=1; i<=((N-n)/2); i++)
    {
        if(i%2)
        {
            (startksztalt)?(putchar('#')):(putchar('o'));

        }
        else
        {
            (startksztalt)?(putchar('o')):(putchar('#'));
        }
    }

    putchar('#');
    for(int i=1; i<=(n-2); i++)
    {
        (ksztalt)?(putchar('#')):(putchar('o'));
    }
    putchar('#');

    for(int i=((N-n)/2); i>=1; i--)
    {
        if(i%2)
        {
            (startksztalt)?(putchar('#')):(putchar('o'));

        }
        else
        {
            (startksztalt)?(putchar('o')):(putchar('#'));
        }
    }


    putchar('\n');

    ksztalt++;
    ksztalt%=2;
    n-=2;
}

ksztalt=startksztalt;
for(int i=1; i<=N; i++)
{
    (ksztalt)?(putchar('#')):(putchar('o'));
    ksztalt++;
    ksztalt%=2;
}
putchar('\n');



n=3;
//ksztalt=(startksztalt+1)%2;

((n/2)%2)?(ksztalt=0):(ksztalt=1);


while(n<N)
{
    for(int i=1; i<=((N-n)/2); i++)
    {
        if(i%2)
        {
            (startksztalt)?(putchar('#')):(putchar('o'));

        }
        else
        {
            (startksztalt)?(putchar('o')):(putchar('#'));
        }
    }

    putchar('#');
    for(int i=1; i<=(n-2); i++)
    {
        (ksztalt)?(putchar('#')):(putchar('o'));
    }
    putchar('#');

    for(int i=((N-n)/2); i>=1; i--)
    {
        if(i%2)
        {
            (startksztalt)?(putchar('#')):(putchar('o'));

        }
        else
        {
            (startksztalt)?(putchar('o')):(putchar('#'));
        }
    }


    putchar('\n');

    ksztalt++;
    ksztalt%=2;
    n+=2;
}






    putchar('#');
    for(int i=1; i<=(N-2); i++)
    {
        (startksztalt)?(putchar('#')):(putchar('o'));
    }
    
    putchar('#');

    return 0;
}
