#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "z1.h"

//Patryk Maciąg, 331542, zadanie 1

int main()
{

    Figura *f[3]={new_square(1,-1,3), new_circle(3, 4, 5), new_triangle(11, 1.2, 3.5)};

    show(f[0]);
    show(f[1]);
    show(f[2]);

    printf("%f\n", sumapol(f,3));
    return 0;
}
