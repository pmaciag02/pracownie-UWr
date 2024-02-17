#include <iostream>
#include "zmienne.hpp"

using namespace std;



int main()
{

zmienna x = zmienna();
zmienna y = zmienna("ala");
zmienna z = zmienna("kot", 3);


cout << x.get_nazwa() << " " << x.get_wartosc() << '\n';
cout << y.get_nazwa() << " " << y.get_wartosc() << '\n';
cout << z.get_nazwa() << " " << z.get_wartosc() << '\n';


x.set_wartosc(5);
cout << x.get_nazwa() << " " << x.get_wartosc() << '\n';


zbior_zmiennych t = zbior_zmiennych(10);


t.set_zmienna(x);
t.set_zmienna(y);
t.set_zmienna(z);


cout << t.get_zmienna("ala") << '\n';
t.delete_zmienna("ala");
cout << t.get_zmienna("ala") << '\n';


if(t.sprawdz("kot"))
{
cout << t.get_zmienna("kot") << '\n';
}
else
{
cout << "brak zmiennej w zbiorze\n";
}


t.modyfikacja("kot", 33);
cout << t.get_zmienna("kot") << '\n';

z.~zmienna();
cout << "nie ma kota\n";

if(t.sprawdz("kot"))
{
cout << t.get_zmienna("kot") << '\n';
}
else
{
cout << "brak zmiennej w zbiorze\n";
}
t.~zbior_zmiennych();
cout << "nie ma zbioru\n";
return 0;
}
