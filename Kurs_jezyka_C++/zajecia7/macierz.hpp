#ifndef MACIERZ_HPP_INCLUDED
#define MACIERZ_HPP_INCLUDED

#include <iostream>

//Patryk Maciąg

using namespace std;

namespace obliczenia
{


class wektor
{
    double *tab = nullptr;
    const int k;

public:
    wektor(int k);
    wektor(initializer_list<double> lista);
    wektor(const wektor &v);
    wektor(wektor &&v);
    ~wektor();

    wektor& operator=(const wektor &v);
    wektor& operator=(wektor &&v);

    double operator[](int i) const;
    double& operator[](int i);

    friend istream& operator>>(istream &is, wektor &v);
    friend ostream& operator<<(ostream &os, const wektor &v);

    friend wektor operator-(const wektor &v); //zmiana znaku
    friend wektor operator+(const wektor &x, const wektor &y);
    friend wektor operator-(const wektor &x, const wektor &y);
    friend wektor operator*(const wektor &v, double d);
    friend wektor operator*(double d, const wektor &v);
    //iloczyn skalarny
    friend double operator*(const wektor &x, const wektor &y);
    wektor& operator+=(const wektor &v);
    wektor& operator-=(const wektor &v);
    wektor& operator*=(double d);

    int dlugosc() const;
};



class macierz
{
    wektor **tab = nullptr;
    const int w, k;

public:
    macierz(int w, int k);
    macierz(initializer_list<wektor> lista);
    macierz(const macierz &m);
    macierz(macierz &&m);
    ~macierz();

    macierz& operator=(const macierz &m);
    macierz& operator=(macierz &&m);

    obliczenia::wektor operator[](int i) const;
    obliczenia::wektor& operator[](int i);

    friend istream& operator>>(istream &is, macierz &m);
    friend ostream& operator<<(ostream &os, const macierz &m);

    friend macierz operator-(const macierz &m);
    friend macierz operator+(const macierz &p, const macierz &q);
    friend macierz operator-(const macierz &p, const macierz &q);
    friend macierz operator*(const macierz &m, double d);
    friend macierz operator*(double d, const macierz &m);
    friend macierz operator*(const macierz &p, const macierz &q);
    friend macierz operator~(const macierz &m);
    macierz& operator+=(const macierz &m);
    macierz& operator-=(const macierz &m);
    macierz& operator*=(double d);
};


}

#endif
