#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{

    if(argc<4)
    {
        fprintf(stderr, "Użycie: %s <plik docelowy> <liczba kopiowanych wierszy> plik1 plik2 ...\n", argv[0]);
        exit(2);
    }

    FILE *f,*wyniki;

    wyniki=fopen(argv[1], "w");
    if(wyniki==NULL)
    {
        fprintf(stderr, "%s: błąd utworzenia pliku: %s\n", argv[0], argv[1]);
        exit(2);
    }

    int n=0;
    for(int i=0; i<strlen(argv[2]); i++)
    {
        n*=10;
        n+=argv[2][i]-48;
    }



    for(int i=3; i<argc; i++)
    {
        f=fopen(argv[i], "r");

        if(f==NULL)
        {
            fprintf(stderr, "%s: błąd otwarcia pliku: %s\n", argv[0], argv[i]);
            exit(2);
        }
        int c, wiersze=0;
        while((c=getc(f))!=EOF)
        {
            if(c=='\n') wiersze++; //musi byc na poczatku
        }
        fprintf(wyniki, "\nNazwa pliku: %s (%d)\n", argv[i], wiersze);
        fclose(f);

        f=fopen(argv[i], "r");

        if(f==NULL)
        {
            fprintf(stderr, "%s: błąd otwarcia pliku: %s\n", argv[0], argv[i]);
            exit(2);
        }
        wiersze=0;
        while((c=getc(f))!=EOF)
        {
            if(c=='\n') wiersze++;
            putc(c, wyniki);
            if(wiersze==n) break;
        }
        // if(c!=EOF)
        // {
        //     while((c=getc(f))!=EOF)
        //     {
        //         if(c=='\n') wiersze++; //musi byc na poczatku
        //     }
        // }
        fclose(f);
    }



    fclose(wyniki);


    return 0;
}