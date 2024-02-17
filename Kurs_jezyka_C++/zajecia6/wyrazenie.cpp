#include <iostream>
#include <vector>
#include <cmath>
#include "wyrazenie.hpp"

//Patryk Maciąg

using namespace std;


vector<pair<string, double>> Zmienna::zmienne;

Liczba::Liczba(double w) : wartosc(w)
{

}

string Liczba::zapis()
{
    return to_string(wartosc);
}

double Liczba::oblicz()
{
    return wartosc;
}

Zmienna::Zmienna(string z) : Zmienna_nazwa(z)
{

}

string Zmienna::zapis()
{
    return Zmienna_nazwa;
}

double Zmienna::oblicz()
{
    int n = Zmienna::zmienne.size();
    for (int i = 0; i < n; i++)
    {
        if (Zmienna::zmienne[i].first == Zmienna_nazwa)
            return Zmienna::zmienne[i].second;
    }

    throw "brak zmiennej";
    return 0;
}

void Zmienna::dodajZmienna(string z, double v)
{
    int n = Zmienna::zmienne.size();
    for (int i = 0; i < n; i++)
    {
        if (Zmienna::zmienne[i].first == z)
        {
            cerr << "Zmienna istnieje.\n";
            return;
        }
    }

    Zmienna::zmienne.push_back(make_pair(z, v));
}

void Zmienna::usunZmienna(string z)
{
    int n = Zmienna::zmienne.size();
    for (int i = 0; i < n; i++)
    {
        if (Zmienna::zmienne[i].first == z)
        {
            Zmienna::zmienne.erase(Zmienna::zmienne.begin() + i);
            return;
        }
    }
    throw "brak zmiennej";
}

void Zmienna::modyfikujZmienna(string z, double v)
{
    int n = Zmienna::zmienne.size();
    for (int i = 0; i < n; i++)
    {
        if (Zmienna::zmienne[i].first == z)
        {
            Zmienna::zmienne.erase(Zmienna::zmienne.begin() + i);
            Zmienna::zmienne.push_back(make_pair(z, v));
            return;
        }
    }
    throw "brak zmiennej";
}


pi::pi()
{
    wartosc = 3.141592;
}

string pi::zapis()
{
    return "pi";
}

double pi::oblicz()
{
    return wartosc;
}

e::e()
{
    wartosc = 2.718281;
}

string e::zapis()
{
    return "e";
}

double e::oblicz()
{
    return wartosc;
}

fi::fi()
{
    wartosc = 1.618033;
}

string fi::zapis()
{
    return "fi";
}

double fi::oblicz()
{
    return wartosc;
}

Operator1arg::Operator1arg(Wyrazenie *arg1)
{
    this->arg1 = arg1;
}

Przeciw::Przeciw(Wyrazenie *arg1) : Operator1arg(arg1) {

}

string Przeciw::zapis()
{
    return "-(" + arg1->zapis() + ")";
}

double Przeciw::oblicz()
{
    return (-1) * arg1->oblicz();
}

Odwrot::Odwrot(Wyrazenie *arg1) : Operator1arg(arg1) {

}

string Odwrot::zapis()
{
    return "1 / " + arg1->zapis();
}

double Odwrot::oblicz()
{
    return 1.0 / arg1->oblicz();
}

Abs::Abs(Wyrazenie *arg1) : Operator1arg(arg1) {

}

string Abs::zapis()
{
    return "|" + arg1->zapis() + "|";
}

double Abs::oblicz()
{
    if (arg1->oblicz() < 0)
        return (-1) * arg1->oblicz();
    else
        return arg1->oblicz();
}

Exp::Exp(Wyrazenie *arg1) : Operator1arg(arg1) {

}

string Exp::zapis()
{
    return "exp(" + arg1->zapis() + ")";
}

double Exp::oblicz()
{
    return exp(arg1->oblicz());
}

Ln::Ln(Wyrazenie *arg1) : Operator1arg(arg1) {

}

string Ln::zapis()
{
    return "ln(" + arg1->zapis() + ")";
}

double Ln::oblicz()
{
    return log(arg1->oblicz());
}

Sin::Sin(Wyrazenie *arg1) : Operator1arg(arg1) {

}

string Sin::zapis()
{
    return "sin(" + arg1->zapis() + ")";
}

double Sin::oblicz()
{
    return sin(arg1->oblicz());
}

Cos::Cos(Wyrazenie *arg1) : Operator1arg(arg1) {

}

string Cos::zapis()
{
    return "cos(" + arg1->zapis() + ")";
}

double Cos::oblicz()
{
    return cos(arg1->oblicz());
}

Operator2arg::Operator2arg(Wyrazenie *arg1, Wyrazenie *arg2) : Operator1arg(arg1), arg2(arg2)
{

}

Dodaj::Dodaj(Wyrazenie *arg1, Wyrazenie *arg2) : Operator2arg(arg1, arg2)
{

}



pair<string, string> Operator2arg::translacja()
{
    string l, r;

    if (arg1->priorytet() > priorytet()){
        l = arg1->zapis();

    }else if (arg1->priorytet() < priorytet()){
        l = "(" + arg1->zapis() + ")";

    }else if (arg1->lewostronne()){
        l = arg1->zapis();

    }else{
        l = "(" + arg1->zapis() + ")";
    }



    if (arg2->priorytet() > priorytet()){
        r = arg2->zapis();

    }else if (arg2->priorytet() < priorytet()){
        r = "(" + arg2->zapis() + ")";

    }else if (arg2->lewostronne()){
        r = arg2->zapis();

    }else{
        r = "(" + arg2->zapis() + ")";
    }

    return make_pair(l,r);
}

string Dodaj::zapis()
{
    pair<string,string> p = translacja();

    return p.first + " + " + p.second;
}

double Dodaj::oblicz()
{
    return arg1->oblicz() + arg2->oblicz();
}

Odejmij::Odejmij(Wyrazenie *arg1, Wyrazenie *arg2) : Operator2arg(arg1, arg2)
{

}

string Odejmij::zapis()
{
    pair<string,string> p = translacja();

    return p.first + " - " + p.second;
}

double Odejmij::oblicz()
{
    return arg1->oblicz() - arg2->oblicz();
}

Mnoz::Mnoz(Wyrazenie *arg1, Wyrazenie *arg2) : Operator2arg(arg1, arg2)
{

}

string Mnoz::zapis()
{
    pair<string,string> p = translacja();

    return p.first + " * " + p.second;
}

double Mnoz::oblicz()
{
    return arg1->oblicz() * arg2->oblicz();
}

Dziel::Dziel(Wyrazenie *arg1, Wyrazenie *arg2) : Operator2arg(arg1, arg2)
{

}

string Dziel::zapis()
{
    pair<string,string> p = translacja();

    return p.first + " / " + p.second;
}

double Dziel::oblicz()
{
    return arg1->oblicz() / arg2->oblicz();
}

Potega::Potega(Wyrazenie *arg1, Wyrazenie *arg2) : Operator2arg(arg1, arg2)
{

}

string Potega::zapis()
{
    //pair<string,string> p = translacja();

    //return p.first + " ^ " + p.second;

    string l, r;

    if (arg1->priorytet() > priorytet()){
        l = arg1->zapis();

    }else if (arg1->priorytet() < priorytet()){
        l = "(" + arg1->zapis() + ")";

    }else if (arg1->lewostronne()){
        l = arg1->zapis();

    }else{
        l = "(" + arg1->zapis() + ")";
    }



    if (arg2->priorytet() > priorytet()){
        r = arg2->zapis();

    }else if (arg2->priorytet() < priorytet()){
        r = "(" + arg2->zapis() + ")";

    }else if (arg2->lewostronne()){
        r = "(" + arg2->zapis() + ")";
       // r = arg2->zapis();

    }else{
        //r = "(" + arg2->zapis() + ")";
        r = arg2->zapis();
    }

    return l + " ^ " + r;
}

double Potega::oblicz()
{
    return pow(arg1->oblicz(), arg2->oblicz());
}

Mod::Mod(Wyrazenie *arg1, Wyrazenie *arg2) : Operator2arg(arg1, arg2)
{

}

string Mod::zapis()
{
    pair<string,string> p = translacja();

    return p.first + " % " + p.second;
}

double Mod::oblicz()
{
    return fmod(arg1->oblicz(), arg2->oblicz());
}


Log::Log(Wyrazenie *arg1, Wyrazenie *arg2) : Operator2arg(arg1, arg2)
{

}

string Log::zapis()
{
    return "log(" + arg1->zapis() + ", " + arg2->zapis() + ")";
}

double Log::oblicz()
{
    return (log (arg2->oblicz())) / (log (arg1->oblicz()));
}

