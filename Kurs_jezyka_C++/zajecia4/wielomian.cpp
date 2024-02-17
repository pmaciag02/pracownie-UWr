#include <iostream>
//#include <cstring>
#include <initializer_list>
//#include <list>
#include "wielomian.hpp"



//Patryk Maciąg



using namespace std;


wielomian::wielomian () : n(0), a(nullptr)
{
    a = new double[n+1];
    a[0]=1;
}


wielomian::wielomian (int st, const double wsp[]) : n(st), a(nullptr)
{
    a = new double[n+1];

    for(int i=0; i<=n; i++)
    {
        a[i]=wsp[i];
    }
}


wielomian::wielomian (initializer_list<double> wsp) : n(wsp.size()-1), a(nullptr)
{
    a = new double[n+1];

    auto it = wsp.begin();

    for(int i=0; i<=n; i++)
    {
        a[n-i]=*it;
        it++;
    }
}


wielomian::wielomian (const wielomian &w) : n(w.n), a(nullptr)
{
    a = new double[n+1];
    copy(w.a, w.a+n+1, a);
}


wielomian::wielomian (wielomian &&w) : n(w.n), a(nullptr)
{
    a = new double[n+1];
    a = w.a;
    w.n = 0;
    w.a = nullptr;
}


wielomian& wielomian::operator = (const wielomian &w)
{
    if(this == &w) return *this;

    this->~wielomian();
    n = w.n;
    a = new double[n+1];

    copy(w.a, w.a+n+1, a);

    return *this;
}


wielomian& wielomian::operator = (wielomian &&w)
{
    if(this == &w) return *this;

    this->~wielomian();
    n = w.n;
    a = new double[n+1];

    a = w.a;

    w.n = 0;
    w.a = nullptr;

    return *this;
}


wielomian::~wielomian ()
{
    a = nullptr;
    delete[] a;
}


istream& operator >> (istream &we, wielomian &w)
{

    cout << "Podaj stopień wielomianu:\n";
    we >> w.n;
    w.a = nullptr;
    delete[] w.a;
    w.a = new double[w.n+1];
    cout << "Podaj współczynniki wielomianu od najistotniejszego:\n";
    for(int i=w.n; i>=0; i--)
    {
        we >> w.a[i];
    }
    return we;
}


ostream& operator << (ostream &wy, const wielomian &w)
{

    wy << "stopień: " << w.n << ", współczynniki:";

    for(int i=w.n; i>=0; i--)
    {
        wy << " " << w.a[i];
    }
    wy << '\n';
    return wy;
}



wielomian operator + (const wielomian &u, const wielomian &v)
{

    if(u.n > v.n)
    {
        wielomian w = wielomian(u);

        for(int i=0; i<=v.n; i++)
        {
            w.a[i] += v.a[i];
        }

        return w;
    }
    else
    {
        wielomian w = wielomian(v);

        for(int i=0; i<=u.n; i++)
        {
            w.a[i] += u.a[i];
        }

        return w;
    }


}


wielomian operator - (const wielomian &u, const wielomian &v)
{
    double *t = new double[max(u.n, v.n)+1];

    for(int i=0; i<=max(u.n, v.n); i++)
    {
        t[i]=0;
        if(i <= u.n) t[i] += u.a[i];
        if(i <= v.n) t[i] -= v.a[i];
    }

    return wielomian(max(u.n, v.n), t);
}


wielomian operator * (const wielomian &u, const wielomian &v)
{
    double *t = new double[u.n+v.n+1];
    t = {0};

    for(int i=0; i<=u.n; i++)
    {
        for(int j=0; j<=v.n; j++)
        {
            t[i+j] += u.a[i]*v.a[j];
        }
    }

    return wielomian(u.n+v.n, t);
}


wielomian operator * (double c, const wielomian &u)
{
    wielomian w = u;

    for(int i=0; i<=w.n; i++)
    {
        w.a[i] *=c;
    }

    return w;
}


wielomian& wielomian::operator += (const wielomian &v)
{
    if(n > v.n)
    {
        wielomian w = wielomian(n, a);

        for(int i=0; i<=v.n; i++)
        {
            w.a[i] += v.a[i];
        }

        n = w.n;
        a = w.a;
        return *this;
    }
    else
    {
        wielomian w = wielomian(v);

        for(int i=0; i<=n; i++)
        {
            w.a[i] += a[i];
        }

        n = w.n;
        a = w.a;
        return *this;
    }
}


wielomian& wielomian::operator -= (const wielomian &v)
{
    double *t = new double[max(n, v.n)+1];

    for(int i=0; i<=max(n, v.n); i++)
    {
        t[i]=0;
        if(i <= n) t[i] += a[i];
        if(i <= v.n) t[i] -= v.a[i];
    }

    n = max(n, v.n);
    a = t;
    return *this;
}


wielomian& wielomian::operator *= (const wielomian &v)
{
    double *t = new double[n+v.n+1];
    t = {0};

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=v.n; j++)
        {
            t[i+j] += a[i]*v.a[j];
        }
    }
    a=t;
    return *this;
}


wielomian& wielomian::operator *= (double c)
{

    for(int i=0; i<=n; i++)
    {
        a[i] *=c;
    }

    return *this;
}



double wielomian::operator () (double x) const
{
    double wynik=0;
    double l = 1;
    for(int i=0; i<=n; i++)
    {
        wynik+=a[i]*l;
        l*=x;
    }

    return wynik;
}

double wielomian::operator [] (int i) const
{
    return a[i];
}

double& wielomian::operator [] (int i)
{
    return a[i];
}

