#include <stdio.h>


int m,s,n,N[1005],W[1005];

int main()
{
    scanf("%d%d%d",&m,&s,&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&N[i],&W[i]);
    }


    int k=1, floor=0, a=0, last;
    s++;
    while(s--)
    {
        last=floor;
        (a<W[floor])?(a=0):(a-=W[floor]);
        if(s==0)break;
        if(a+N[floor]>m)
        {
            N[floor]=a+N[floor]-m;
            //N[floor]=x;
            a=m;
        }
        else
        {
            a+=N[floor];
            //N[floor]=0;
        }
        floor+=k;
        if(floor==(n-1))k=-1;
        if(floor==0)k=1;
    }

    printf("%d %d", last, a);
    
    return 0;
}
