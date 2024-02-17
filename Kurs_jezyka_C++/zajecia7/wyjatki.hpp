#ifndef WYJATKI_HPP
#define WYJATKI_HPP

#include <iostream>
#include <stdexcept>

//Patryk Maciąg

using namespace std;

class dimentions_error : public logic_error
{
public:
    dimentions_error() : logic_error("Różne wymiary")
    {}
};

class size_error : public logic_error
{
public:
    size_error() : logic_error("Niedodatni rozmiar")
    {}
};


class index_error : public logic_error
{
public:
    index_error() : logic_error("Zły indeks")
    {}
};

#endif
