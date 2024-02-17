#include <iostream>
//#include <cstring>
#include <initializer_list>
//#include <list>
#include "wielomian.hpp"



//Patryk Maciąg



using namespace std;


int main()
{

    wielomian w = wielomian({3, 2, 1});
    wielomian w2 = wielomian({6, 5, 4});
    w2 += w;
    cout << w2 <<'\n';

    wielomian v;
    cin >> v;
    cout << v;
    cout << "wartość wielomianu od 2: " << v(2) << '\n';
    cout << "współczynnik przy 2. stopniu: " << v[2] << '\n';
    return 0;
}
