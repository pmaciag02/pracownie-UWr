#include <stdio.h>
#include <string.h>

char z[1000];
int od,doo,w[1000];

int main(int argc, char *argv[])
{
    if (argc <= 1) { printf("Brak argumentow \n"); return 1; }
    
    for(int i=0; i<argc; i++)
    {
        int ile=sscanf(argv[i], "%d-%d", &od, &doo);
        if(ile==1)
        {
            w[od]=1;
        }else{
            for(int j=od; j<=doo; j++){
                w[j]=1;
            }
        }
    }
    //for(int i=1; i<10; i++){printf("%d",w[i]);}
    int n, l=0, s=1;
    char t[1000];
    while((n=getchar())!=EOF){
        if(n==' '|| n=='\n' || n=='\t')
        {
            if(l>0){

                if(w[s])
                {
                printf("%.*s ",l,t);
                //strcpy(t,"");
                //printf("%s ",t);
                }
                s++;
                l=0;
            }
            continue;
        }
        t[l]=n;
        l++;
    }

    return 0;
}