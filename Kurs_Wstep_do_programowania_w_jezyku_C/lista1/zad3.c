#include <stdio.h>
#include <math.h>


int main()
{
    int n, t[100005], t2[100005];
    scanf("%d",&n);
    if((n<4)||(n>100000))
    {
        printf("NIEPOPRAWNA LICZBA");
        return 0;
    }
    if(!n%2)
    {
        printf("NIEPOPRAWNA LICZBA");
        return 0;
    }
    for(int i=2; i*i<=n; i++){
        if(t[i]) continue;
        for(int j=i+i; j<=n; j+=i){
            t[j]=1;
        }
    }

    t[0]=1;
    t[1]=1;

    int ok=0;
    for(int i=2; i<=n; i++)
    {
        if(t[i])continue;
        if(t[n-i])continue;
        if(t2[i])continue;
        ok=1;
        t2[i]=1;
        t2[n-i]=1;
        printf("%d %d ", i, n-i);
    }
    if(!ok) printf("NIEPOPRAWNA LICZBA");
    return 0;
}
