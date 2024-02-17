#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int n, perm[100];


bool next_perm(int n, int perm[n])
{
    if(n==1) return 1;
    int dalej=0;
    for(int i=1; i<=n; i++)
    {
        if(perm[i]!=i)
        {
            dalej=1;
            break;
        }
    }
    if(!dalej)return 0;

    if(perm[n]==n)
    {
        if(next_perm(n-1, perm))
        {
        for(int i=n; i>1; i--)
        {
            perm[i]=perm[i-1];
        }
        perm[1]=n;
        }
    }
    else
    {
        for(int i=1; i<n; i++)
    {
        if(perm[i]==n)
        { 
        perm[i]=perm[i+1];
        perm[i+1]=n;
        break;
        }
    }
        return 1;
    }

}




int main()
{
scanf("%d", &n);
if(n==1)putchar('1');
for(int i=0; i<n; i++)
{
    perm[i+1]=n-i;
}
//int licznik=0;
do
{
    //licznik++;
    //printf("%d) ", licznik);
for(int i=1; i<=n; i++)
{
    printf("%d ", perm[i]);
}
putchar('\n');




}while(next_perm(n, perm));



    return 0;
}