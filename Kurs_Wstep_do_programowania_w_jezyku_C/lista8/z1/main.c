#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "wllc.h"
#define aN addNumber
#define aS addSublist


//Patryk Maciąg, 331542, lista 8, zad. 1



int main()
{
    List L=Init();
    L=aN(3,L);
    print(L);
    putchar('\n');
    L=aN(5,L);
    print(L);
    putchar('\n');

    List L2=Init();
    L2=aN(8,L2);
    L2=aN(9,L2);
    print(L2);
    putchar('\n');
    L=aS(L2,L);
    print(L);
    putchar('\n');
    List x=aS(Init(), Init());
    print(x);
    putchar('\n');
    List y=aN(7, Init());
    print(y);
    putchar('\n');
    List z=aN(4, y);
    print(z);
    putchar('\n');
    List v=aS(z, x);
    print(v);
    putchar('\n');
    List w=aN(2, v);
    print(w);
    putchar('\n');

    List L3=aN(2,aS(aN(4, aN(7, Init())), aS(Init(), Init())));
    print(L3);
    putchar('\n');

    List L4=flat(L); //nie działa, zwraca ostatnii węzeł nowej listy zamiast pierwszego
    print(L4);
    putchar('\n');


    return 0;
}
