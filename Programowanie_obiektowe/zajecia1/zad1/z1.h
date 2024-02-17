#include <stdlib.h>
#include <stdio.h>

//Patryk Maciąg, 331542, zadanie 1

typedef struct figura{
float x;
float y;
float z;
int typfig;
}Figura;

Figura *new_square(float x, float y, float a);
Figura *new_circle(float x, float y, float r);
Figura *new_triangle(float x, float y, float a);
float pole(Figura *f);
void przesun(Figura *f, float x, float y);
void show(Figura *f);
float sumapol(Figura* f[], int size);
