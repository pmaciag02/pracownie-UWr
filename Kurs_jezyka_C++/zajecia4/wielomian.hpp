#ifndef NAPIS_HPP_INCLUDED
#define NAPIS_HPP_INCLUDED

#include <iostream>

//Patryk Maciąg


using namespace std;


class wielomian {

int n; // stopień wielomianu
double *a; // współczynniki wielomianu;


public:
    //wielomian (int st=0, double wsp=1.0); // konstruktor jednomianu
    wielomian ();
    wielomian (int st, const double wsp[]); // konstruktor wielomianu
    wielomian (initializer_list<double> wsp); // lista współczynników
    wielomian (const wielomian &w); // konstruktor kopiujący
    wielomian (wielomian &&w); // konstruktor przenoszący
    wielomian& operator = (const wielomian &w); // przypisanie kopiujące
    wielomian& operator = (wielomian &&w); // przypisanie przenoszące
    ~wielomian (); // destruktor

public:
    friend istream& operator >> (istream &we, wielomian &w);
    friend ostream& operator << (ostream &wy, const wielomian &w);

public:
    friend wielomian operator + (const wielomian &u, const wielomian &v);
    friend wielomian operator - (const wielomian &u, const wielomian &v);
    friend wielomian operator * (const wielomian &u, const wielomian &v);
    friend wielomian operator * (double c, const wielomian &u);
    wielomian& operator += (const wielomian &v);
    wielomian& operator -= (const wielomian &v);
    wielomian& operator *= (const wielomian &v);
    wielomian& operator *= (double c);
    double operator () (double x) const; // wartość wielomianu dla x
    double operator [] (int i) const; // do odczytu współczynnika
    double& operator [] (int i); // do zapisu współczynnika
};




#endif
