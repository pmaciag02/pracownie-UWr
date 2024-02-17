#include <iostream>
#include <fstream>
#include "cezar.hpp"

//Patryk Maciąg

using namespace std;


wejscie::wejscie(string tekst)
{
    plik.open(tekst.c_str());
    if (plik.fail()) throw ios_base::failure("Błąd failbit lub badbit.");
}

wejscie::~wejscie()
{
    plik.close();
}



string wejscie::nastlinia()
{
    string linia;
    getline(plik, linia);
    return linia;
}




wyjscie::wyjscie(string tekst)
{
    plik.open(tekst.c_str());
    if (plik.fail()) throw ios_base::failure("Błąd failbit lub badbit.");
}


wyjscie::~wyjscie()
{
    plik.close();
}



void wyjscie::piszlinie(string s)
{
    plik << s << '\n';
}



void cezar(string plik_we, string plik_wy, int klucz)
{
    wejscie we(plik_we);
    wyjscie wy(plik_wy);
    string tekst;
    while((tekst = we.nastlinia()) != ""){
    int dlugosc = tekst.length();
    for(int i=0; i<dlugosc; i++){
        int t=tekst[i];
        if(t >='a' && t <= 'z')
        {
            t = (t-'a'+klucz)%26;
            t+='a';
            tekst[i] = t;
        }
        else if(t >='A' && t <= 'Z')
        {
            t = (t-'A'+klucz)%26;
            t+='A';
            tekst[i] = t;
        }
    }
    wy.piszlinie(tekst);
    }

}

