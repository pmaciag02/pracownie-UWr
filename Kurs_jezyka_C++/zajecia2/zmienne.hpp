#ifndef MY_HEADER_HPP
#define MY_HEADER_HPP
#include <iostream>

using namespace std;




class zmienna {
private:
    string nazwa;
    double wartosc;
public:
    zmienna();
    zmienna(string a, double b);
    zmienna(string a);
    ~zmienna();
public:
    string get_nazwa();
    void set_wartosc(double b);
    double get_wartosc();
};



class zbior_zmiennych {
//private:
    const int n;
    zmienna *tab;
public:
    zbior_zmiennych(const int a);
    ~zbior_zmiennych();
public:
    void set_zmienna(zmienna a);
    bool sprawdz(string a);
    double get_zmienna(string a);
    void delete_zmienna(string a);
    void modyfikacja(string a, double b);

};
#endif // end-of-header-guard
