#include <stdio.h>
#include <math.h>

//Patryk Maciąg Lista1 zad.1.

const double e_1=2.71828182845904523536028747135266249775724709369995;
const long double e_2=2.71828182845904523536028747135266249775724709369995L;

int main(void)
{
printf("Dla szeregu:\n");
double e=1,n=20,licznik=1;

for(double i=1; i<=n; i++){
licznik*=i;
e+=(1/licznik);
//printf("%f\n",e);
}
printf("e dla double = %.20f\n",e);

long double e2=1L, licznik2=1L;
for(long double i=1L; i<=n; i++){
licznik2*=i;
e2+=(1/licznik2);
//printf("%f\n",e);
}
printf("e dla long double = %.20Lf\n",e2);

printf("Różnica e dla double = %g\n", e_1-e);
printf("Różnica e dla long double = %Lg\n", e_2-e2);



printf("Dla limensa:\n");
n=200000;

e=1+(1/n);
licznik=e;
for(double i=1; i<n; i++){
e*=licznik;
//printf("%f\n",e);
}
printf("e dla double = %.20f\n",e);

e2=1+(1/n);
licznik2=e2;
for(long double i=1L; i<n; i++){
e2*=licznik2;
//printf("%Lf\n",e);
}
printf("e dla long double = %.20Lf\n",e2);


printf("Różnica e dla double = %g\n", e_1-e);
printf("Różnica e dla long double = %Lg\n", e_2-e2);

return 0;
}
