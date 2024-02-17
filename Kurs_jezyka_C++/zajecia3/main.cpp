#include <iostream>
#include "kolejka.hpp"

//Patryk Maciąg


using namespace std;

int main()
{

    kolejka k1 = kolejka(5);

    k1.wstaw("Ala");
    k1.wstaw("ma");
    k1.wstaw("kota");

    cout << k1.usun() << " " << k1.usun() << " " << k1.zprzodu() << " " << k1.usun() << '\n';

    k1.wstaw("Andrzej");
    k1.wstaw("to");
    k1.wstaw("kłamca");
    k1.wstaw("i");
    k1.wstaw("złodziej");

    kolejka k2 = k1;
    cout << k1.dlugosc() << " " << k1.usun() << " " << k1.usun() << " " << k1.usun() << " " << k1.usun() << " " << k1.usun() << '\n';
    cout << k2.dlugosc() << " " << k2.usun() << " " << k2.usun() << " " << k2.usun() << " " << k2.usun() << " " << k2.usun() << '\n';

    kolejka k3 = {"Paweł", "Adam", "Kuba", "Tomek"};
    kolejka k4;
    k4 = k3;
    cout << k3.dlugosc() << " " << k3.usun() << " " << k3.usun() << " " << k3.usun() << " " << k3.usun() << " " << k3.usun() << '\n';
    cout << k4.dlugosc() << " " << k4.usun() << " " << k4.usun() << " " << k4.usun() << " " << k4.usun() << " " << k4.usun() << '\n';

    kolejka k5 = kolejka({"Pies"});
    cout << k5.dlugosc() << " " << k5.usun() << "\n";

    return 0;
}
