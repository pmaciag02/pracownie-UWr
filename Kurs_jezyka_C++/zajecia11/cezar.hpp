#ifndef CEZAR_HPP_INCLUDED
#define CEZAR_HPP_INCLUDED

#include <iostream>
#include <fstream>

//Patryk Maciąg

using namespace std;




class wejscie
{
    ifstream plik;
public:
    wejscie(string tekst);
    ~wejscie();


    string nastlinia();
};





class wyjscie
{
    ofstream plik;
public:
    wyjscie(string tekst);
    ~wyjscie();


    void piszlinie(string s);
};


void cezar(string plik_we, string plik_wy, int klucz);



#endif
