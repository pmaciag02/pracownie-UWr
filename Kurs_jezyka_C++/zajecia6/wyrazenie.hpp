#ifndef NAPIS_HPP_INCLUDED
#define NAPIS_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <cmath>


//Patryk Maciąg

using namespace std;


class Wyrazenie
{
    public:
        Wyrazenie() = default;
        virtual ~Wyrazenie(){};

    public:
        Wyrazenie(const Wyrazenie&) = delete;
        Wyrazenie(Wyrazenie&&) = delete;
        Wyrazenie& operator=(const Wyrazenie&) = delete;
        Wyrazenie& operator=(Wyrazenie&&) = delete;

        virtual double oblicz() = 0;
        virtual string zapis() = 0;

        virtual int priorytet()
        {
            return 4;
        }

        virtual bool lewostronne()
        {
            return true;
        }
};

class Liczba : public Wyrazenie
{
    public:
        double wartosc;

    public:
        Liczba (double w);

    public:
        string zapis();
        double oblicz();
};

class Zmienna : public Wyrazenie
{
    private:
        static vector<pair<string, double>> zmienne;

    public:
        string Zmienna_nazwa;
        Zmienna(string z);

    public:
        static void dodajZmienna(string z, double v);
        static void usunZmienna(string z);
        static void modyfikujZmienna(string z, double v);

        string zapis();
        double oblicz();
};

class Stala : public Wyrazenie
{
    protected:
        double wartosc;
};

class pi : public Stala
{
    public:
        pi();

    public:
        string zapis();
        double oblicz();
};

class e : public Stala
{
    public:
        e();

    public:
        string zapis();
        double oblicz();
};

class fi : public Stala
{
    public:
        fi();

    public:
        string zapis();
        double oblicz();
};

class Operator1arg : public Wyrazenie
{
    public:
        Wyrazenie *arg1;

    public:
        Operator1arg(Wyrazenie *arg1);
};

class Przeciw : public Operator1arg
{
    public:
        Przeciw(Wyrazenie *arg1);

    public:
        string zapis();
        double oblicz();
};

class Odwrot : public Operator1arg
{
    public:
        Odwrot(Wyrazenie *arg1);

    public:
        string zapis();
        double oblicz();
};

class Abs : public Operator1arg
{
    public:
        Abs(Wyrazenie *arg1);

    public:
        string zapis();
        double oblicz();
};

class Exp : public Operator1arg
{
    public:
        Exp(Wyrazenie *arg1);

    public:
        string zapis();
        double oblicz();
};

class Ln : public Operator1arg
{
    public:
        Ln(Wyrazenie *arg1);

    public:
        string zapis();
        double oblicz();
};

class Sin : public Operator1arg
{
    public:
        Sin(Wyrazenie *arg1);

    public:
        string zapis();
        double oblicz();
};

class Cos : public Operator1arg
{
    public:
        Cos(Wyrazenie *arg1);

    public:
        string zapis();
        double oblicz();
};

class Operator2arg : public Operator1arg
{
    public:
        Wyrazenie *arg2;

    public:
        Operator2arg(Wyrazenie *arg1, Wyrazenie *arg2);

        int priorytet() override
        {
            return 1;
        }

        virtual bool lewostronne() = 0;

        pair<string, string> translacja();

};

class Dodaj : public Operator2arg
{
    public:
        Dodaj(Wyrazenie *arg1, Wyrazenie *arg2);

    public:
        string zapis();
        double oblicz();

        bool lewostronne() override
        {
            return true;
        }

};

class Odejmij : public Operator2arg
{
    public:
        Odejmij(Wyrazenie *arg1, Wyrazenie *arg2);

    public:
        string zapis();
        double oblicz();

        bool lewostronne() override
        {
            return true;
        }

};

class Mnoz : public Operator2arg
{
    public:
        Mnoz(Wyrazenie *arg1, Wyrazenie *arg2);

    public:
        string zapis();
        double oblicz();

        int priorytet() override
        {
            return 2;
        }

        bool lewostronne() override
        {
            return true;
        }

};

class Dziel : public Operator2arg
{
    public:
        Dziel(Wyrazenie *arg1, Wyrazenie *arg2);

    public:
        string zapis();
        double oblicz();

        int priorytet() override
        {
            return 2;
        }

        bool lewostronne() override
        {
            return true;
        }

};

class Potega : public Operator2arg
{
    public:
        Potega(Wyrazenie *arg1, Wyrazenie *arg2);

    public:
        string zapis();
        double oblicz();

        int priorytet() override
        {
            return 3;
        }

        bool lewostronne() override
        {
            return true;
        }
};

class Mod : public Operator2arg
{
    public:
        Mod(Wyrazenie *arg1, Wyrazenie *arg2);

    public:
        string zapis();
        double oblicz();

        int priorytet() override
        {
            return 3;
        }

        bool lewostronne() override
        {
            return true;
        }

};

class Log : public Operator2arg
{
    public:
        Log(Wyrazenie *arg1, Wyrazenie *arg2);

    public:
        string zapis();
        double oblicz();

        int priorytet() override
        {
            return 3;
        }

        bool lewostronne() override
        {
            return true;
        }

};

#endif

