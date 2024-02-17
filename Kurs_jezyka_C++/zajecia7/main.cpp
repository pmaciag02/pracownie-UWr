#include <iostream>
#include "macierz.hpp"
#include "wyjatki.hpp"

//Patryk Maciąg


using namespace std;
using namespace obliczenia;

int main()
{
    wektor w1{1, 2, 3};
    wektor w2{4, 5, 6};
    wektor w3{12, 3, 9};

    cout << w1 << "\n";
    cout << w2 << "\n";
    cout << w3 << "\n";
    cout << -w1 << "\n";
    cout << w1 + w2 << "\n";
    cout << w1 - w3 << "\n";
    cout << w1 * w2 << "\n";
    cout << w1 * 2 << "\n";
    w1 += w2;
    cout << w1 << "\n";


    macierz m1{{1, 1}, {0, 1}};
    macierz m2{{1, 2}, {3, 4}};

    cout << m1 << "\n";
    cout << m2 << "\n";
    cout << ~m1 << "\n";
    cout << -m1 << "\n";
    cout << m1 + m2 << "\n";
    cout << m1 - m2 << "\n";
    cout << m1 * m2 << "\n";
    cout << m1 * 2 << "\n";
    m1 += m2;
    cout << m1 << "\n";



    return 0;
}
