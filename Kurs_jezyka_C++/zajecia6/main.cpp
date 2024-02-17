#include <iostream>
#include <vector>
#include <cmath>
#include "wyrazenie.hpp"

//Patryk Maciąg

using namespace std;

int main()
{
Zmienna::dodajZmienna("x", 1);


    Wyrazenie *w = new Odejmij(
        new pi(),
        new Dodaj(
            new Liczba(2),
            new Mnoz(
                new Zmienna("x"),
                new Liczba(7)
            )
        )
    );

    Wyrazenie *w2 = new Mnoz(
        new Dodaj(
        new Liczba(1), new Liczba(2)),
        new Dodaj(
        new Liczba(3), new Liczba(4))
        );



    Wyrazenie *w3 = new Potega(
        new Liczba(3),
        new Potega(
            new Liczba(2),
            new Liczba(3))
    );

    Wyrazenie *w4 = new Potega(
        new Potega(
            new Liczba(3),
            new Liczba(3)),
        new Potega(
            new Liczba(2),
            new Liczba(2))
    );

    Wyrazenie *w5 = new Potega(
        new Liczba(3),
        new Potega(
            new Liczba(3),
            new Potega(
                new Liczba(2),
                new Liczba(2))
        ));

    cout << w->oblicz() << "\n" << w->zapis() << "\n";

    cout << w2->oblicz() << "\n" << w2->zapis() << "\n";

    cout << w3->oblicz() << "\n" << w3->zapis() << "\n";

    cout << w4->oblicz() << "\n" << w4->zapis() << "\n";

    cout << w5->oblicz() << "\n" << w5->zapis() << "\n";

    return 0;
}
