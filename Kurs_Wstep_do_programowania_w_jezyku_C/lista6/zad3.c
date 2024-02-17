#include <stdlib.h>
#include <stdio.h>


int main()
{
    int N, M, A, T, ac[10005], st[27][10005];

    scanf("%d %d %d", &N, &M, &A);

    for(int i=0; i<M; i++)
    {
        scanf("%d", &ac[i]);
    }

    for(int i=0; i<A; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &st[i][j]);
        }
    }

    scanf("%d", &T);
    getchar();
    while(T--)
    {
        //getchar();
        //int stan=getchar();
        int stan=0, s;
        //scanf("%d", &stan);
        //printf("stan: %d\n", stan);
        //getchar();

        while((s=getchar())!=' ')
        {
            //printf("stan: %d\n", stan);
            stan*=10;
            stan+=(s-48);
        }


//printf("stan: %d\n", stan);

        int n;

        while((n=getchar())!='\n') //\n
        {
            stan=st[n-97][stan];
            //printf("stan: %d\n", stan);
        }
        int AC=0;
        for(int i=0; i<M; i++)
        {
            if(stan==ac[i])
            {
                AC=1;
                break;
            }
        }

        (AC)?(printf("%d ACCEPT\n", stan)):(printf("%d REJECT\n", stan));

    }

    return 0;
}
