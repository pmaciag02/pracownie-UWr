#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    if(b==0) return a;
    if(b>a) return gcd(b, a);
    return gcd(b, a%b);
}

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    return (a/gcd(a,b))*b;
}


void gcde(unsigned long long a, unsigned long long b, unsigned long long *x, unsigned long long *y)// czy c=xa+by
{
    if(b!=0)
    {
        gcde(b, a%b, x, y);
        unsigned long long z=(*y);
        *y=(*x)-a/b*(*y);
        *x=z;
    }
}


unsigned long long pot(unsigned long long a, unsigned long long b, unsigned long long m)
{
    if(!b) return 1;
    if(b%2) return (a*pot((a*a)%m, b/2, m))%m;
    return pot((a*a)%m, b/2, m); //%m???
}

int main()
{
    unsigned long long N, a, b, m, g, x, y, wynik1, wynik2, xd, n, l, e, d, k, t;
    scanf("%lld", &N);

    char s[10];
    while(N--)
    {
        scanf("%s", s);
        
        if(s[0]=='G' && strlen(s)==3)
        {
            scanf("%lld %lld", &a, &b);
            printf("%lld\n", gcd(a,b));
        }
        else if(s[0]=='L')
        {
            scanf("%lld %lld", &a, &b);
            printf("%lld\n", lcm(a,b));
        }
        else if(s[0]=='G' && strlen(s)==4)
        {
            scanf("%lld %lld", &a, &b);
            g=gcd(a, b), x=1, y=0;
            gcde(a, b, &x, &y);

            xd=x*a+y*b;

            wynik1=x*(g/xd), wynik2=y*(g/xd);

            printf("%lld %lld %lld\n", g, wynik1, wynik2);
        }
        else if(s[0]=='P' && s[1]=='O')
        {
            scanf("%lld %lld %lld", &a, &b, &m);
            printf("%lld\n", pot(a,b,m));
        }
        else if(s[0]=='P' && s[1]=='U')
        {
            scanf("%lld %lld", &a, &b);
            n=a*b;
            l=lcm(a-1, b-1);
            e=3;
            while(1)
            {
                if(gcd(e, l)==1) break;
                e++;
            }
            printf("%lld %lld\n", n, e);
        }
        else if(s[0]=='P' && s[1]=='R')
        {
            scanf("%lld %lld", &a, &b);
            n=a*b;
            l=lcm(a-1, b-1);
            e=3;
            while(1)
            {
                if(gcd(e, l)==1) break;
                e++;
            }
            //e=17;
            d=1, k=0;
            g=gcd(e, l);
            gcde(e, l, &d, &k);
          //  xd=d*e+k*l;
           // d*=(g/xd);
            //k*=(g/xd);
            printf("%lld %lld\n", n, d);
        }
        else if(s[0]=='E')
        {
            scanf("%lld %lld %lld", &n, &e, &t);
            while(t--)
            {
                scanf("%lld", &k);
                printf("%lld ", pot(k,e,n));
            }
            putchar('\n');
        }
        else if(s[0]=='D')
        {
            scanf("%lld %lld %lld", &n, &d, &t);
            while(t--)
            {
                scanf("%lld", &k);
                printf("%lld ", pot(k,d,n));
            }
            putchar('\n');
        }
    }

    return 0;
}

