#include <stdio.h>
#include <string.h>

char z[1000],d[1000];
char t[3000];


int main(int argc, char *argv[])
{
    if(argc<=1){printf("Brak argumentow \n"); return 1;}

    strcpy(z,argv[1]);
    strcpy(d,argv[2]);
    //printf("%s %s\n", z, d);

    int n,l=0;

    while((n=getchar())!=EOF)
    {
        l++;
        if(l>1 && t[l-2]=='\n')
        {
            if(n==' ' || n=='\t')
            {
                l--;
                continue;
            }
        }

        if(l>1 && n>64 && n<91)
        {
            if(t[l-2]=='.')
            {
                t[l+1]=n;
                n=' ';
                t[l-1]=' ';
                t[l]=' ';
                l+=2;
                continue;
            }else if(l>3 && t[l-2]==' '  && t[l-3]=='.'){
                t[l]=n;
                n=' ';
                t[l-1]=n;
                l++;
                continue;
            }
            t[l-1]=n;
            continue;
        }



        
        if(l>1 && t[l-2]==' ' && n==' ')
        {
            l--;
            continue;
        }
        if(l>1 && t[l-2]=='\t' && n=='\t')
        {
            l--;
            continue;

        }
        int ii=strlen(z);
        for(int i=0; i<ii; i++)
        {
            if(n==z[i])
            {
                n=d[i];
                break;
            }
        }
        t[l-1]=n;
    }
   
    printf("%s",t);

    return 0;
}