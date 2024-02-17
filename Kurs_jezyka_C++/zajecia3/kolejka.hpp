#ifndef NAPIS_HPP_INCLUDED
#define NAPIS_HPP_INCLUDED

#include <iostream>
#include <string>

//Patryk Maciąg


using namespace std;

class kolejka {

    int pojemnosc, poczatek=0, ile=0;
    string *tab;

public:
    kolejka(int n);
    kolejka();//konstruktor bezparametrowy i delegatowy
    kolejka(initializer_list<string> a);
    kolejka(const kolejka &k);//konstruktor kopiujący
    kolejka(kolejka &&k);//konstruktor przenoszący
    ~kolejka();
    const kolejka& operator = (const kolejka &k);//przypisanie kopiujace
    const kolejka& operator = (kolejka &&k);//przypisanie przenoszące
public:
    void wstaw(string s);
    string usun();
    string zprzodu();
    int dlugosc();
};



#endif
