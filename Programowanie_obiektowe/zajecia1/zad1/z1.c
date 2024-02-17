#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "z1.h"

//Patryk Maciąg, 331542, zadanie 1



Figura *new_square(float x, float y, float a)
{
Figura *f = malloc(sizeof(Figura));
f->x=x;
f->y=y;
f->z=a;
f->typfig=1;

return f;
}

Figura *new_circle(float x, float y, float r)
{
Figura *f = malloc(sizeof(Figura));
f->x=x;
f->y=y;
f->z=r;
f->typfig=2;

return f;
}


Figura *new_triangle(float x, float y, float a)
{
Figura *f = malloc(sizeof(Figura));
f->x=x;
f->y=y;
f->z=a;
f->typfig=3;

return f;
}


float pole(Figura *f)
{
float p;

if(f->typfig==1)
{
p=(f->z)*(f->z);
}
else if(f->typfig==2)
{
p=(f->z)*(f->z)*M_PI;
}
else
{
p=((f->z)*(f->z)*sqrt(3))/4;
}

return p;
}

void przesun(Figura *f, float x, float y)
{

}


void show(Figura *f)
{
if(f->typfig==1)
{
printf("x: %f, y: %f, dl_boku: %f, pole: %f\n", f->x, f->y, f->z, pole(f));
}
else if(f->typfig==2)
{
printf("x: %f, y: %f, dl_promienia: %f, pole: %f\n", f->x, f->y, f->z, pole(f));
}
else
{
printf("x: %f, y: %f, dl_boku: %f, pole: %f\n", f->x, f->y, f->z, pole(f));
}
}


float sumapol(Figura* f[], int size)
{
float suma=0;
for(int i=0; i<size; i++)
{
    suma+=pole(f[i]);
}
return suma;
}
