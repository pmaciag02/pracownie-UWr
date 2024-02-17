#include <iostream>
#include <stdexcept>
#include "macierz.hpp"
#include "wyjatki.hpp"


//Patryk Maciąg


using namespace std;
using namespace obliczenia;

wektor::wektor(const int k) : k(k)
{
    if(k <= 0) throw size_error();

    tab = new double[k]{0};
}

obliczenia::wektor::wektor(initializer_list<double> lista) : tab(nullptr), k(lista.size())
{
    if(lista.size() <= 0) throw size_error();

    tab = new double[lista.size()];

    auto it = lista.begin();
      for(int i=0; i<k; i++)
      {
        tab[i] = *it;
        it++;
      }
}

wektor::~wektor()
{
    tab = nullptr;
    delete[] tab;
}

wektor::wektor(const wektor &v) : tab(new double[v.k]), k(v.k)
{
    copy(v.tab, v.tab+k, tab);
}

wektor::wektor(wektor &&v) : k(v.k)
{
    tab = v.tab;
    v.tab = nullptr;
}

wektor& wektor::operator=(const wektor &v)
{
    if(this == &v) return *this;

    if(k != v.k) throw dimentions_error();

    copy(v.tab, v.tab+k, tab);

    return *this;
}

wektor& wektor::operator=(wektor &&v)
{
    if(this == &v) return *this;

    this->~wektor();
    *this = wektor(v.k);


    tab = v.tab;
    v.tab = nullptr;

    return *this;
}

double wektor::operator[](const int i) const
{
    if(i < 0 || i >= k) throw index_error();

    return tab[i];
}

double& wektor::operator[](const int i)
{
    if(i < 0 || i >= k) throw index_error();

    return tab[i];
}

wektor& wektor::operator+=(const wektor &v)
{
    if(k != v.k) throw dimentions_error();

    for(int i = 0; i < k; i++)
    {
        tab[i] += v[i];
    }
    return *this;
}

wektor& wektor::operator-=(const wektor &v)
{
    if(k != v.k) throw dimentions_error();

    for(int i=0; i<k; i++)
    {
        tab[i] -= v[i];
    }
    return *this;
}

wektor& wektor::operator*=(const double d)
{
    for(int i=0; i<k; i++)
    {
        tab[i] *= d;
    }
    return *this;
}

namespace obliczenia
{
    istream& operator>>(istream &we, wektor &v)
    {
        for(int i=0; i<v.k; i++)
        {
            we >> v.tab[i];
        }
        return we;
    }

    ostream& operator<<(ostream &wy, const wektor &v)
    {
        for(int i=0; i<v.k; i++)
        {
            wy << v[i] << " ";
        }
        return wy;
    }

    wektor operator-(const wektor &v)
    {
        wektor wynik = v;
        for(int i=0; i<v.k; i++)
        {
            wynik[i] *= -1;
        }
        return wynik;
    }

    wektor operator+(const wektor &x, const wektor &y)
    {
        if(x.k != y.k) throw dimentions_error();

        wektor wynik = x;

        for(int i=0; i<x.k; i++)
        {
            wynik[i] += y[i];
        }
        return wynik;
    }

    wektor operator-(const wektor &x, const wektor &y)
    {
        if(x.k != y.k) throw dimentions_error();

        wektor wynik = x;
        for(int i=0; i<x.k; i++)
        {
            wynik[i] -= y[i];
        }
        return wynik;
    }

    wektor operator*(const wektor &v, double d)
    {
        wektor wynik = v;
        for(int i=0; i<v.k; i++)
        {
            wynik.tab[i] *= d;
        }
        return wynik;
    }

    wektor operator*(double d, const wektor &v)
    {
        return v * d;
    }

    double operator*(const wektor &x, const wektor &y)
    {
        if(x.k != y.k) throw dimentions_error();

        double wynik = 0;

        for(int i=0; i<x.k; i++)
        {
            wynik += x.tab[i] * y.tab[i];
        }
        return wynik;
    }
}

int wektor::dlugosc() const
{
    return k;
}



macierz::macierz(int w, int k) : w(w), k(k)
{
    if(w <= 0 || k <= 0) throw size_error();

    tab = new wektor*[w];

    for(int i=0; i<w; i++)
    {
        tab[i] = new wektor(k);
    }
}

macierz::macierz(initializer_list<wektor> lista) : w(lista.size()), k(lista.begin()->dlugosc())
{
    if(lista.size() <= 0) throw size_error();

    tab = new wektor*[lista.size()];

    auto it = lista.begin();

    for(int i=0; i<w; i++)
    {
        tab[i] = new wektor(*it);
        it++;
    }
}

macierz::~macierz()
{
    for(int i=0; i<w; i++)
    {
        tab[i] = nullptr;
        delete tab[i];
    }
    tab = nullptr;
    delete[] tab;
}

macierz::macierz(const macierz &m) : tab(new wektor*[m.w]), w(m.w), k(m.k)
{
    for (int i=0; i<w; i++)
    {
        tab[i] = new wektor(*m.tab[i]);
    }
}


macierz::macierz(macierz &&m) : tab(m.tab), w(m.w), k(m.k)
{
    m.tab = nullptr;
}

macierz& macierz::operator=(const macierz &m)
{
    if(this == &m) return *this;

    if(w != m.w || k != m.k) throw dimentions_error();

    for(int i=0; i<w; i++)
    {
        *(tab[i]) = *(m.tab[i]);
    }

    return *this;
}

macierz &macierz::operator=(macierz &&m)
{
    if(this == &m) return *this;

    if(w != m.w || k != m.k) throw dimentions_error();

    for(int i=0; i<w; i++)
    {
        tab[i] = nullptr;
        delete tab[i];
    }
    tab = nullptr;
    delete[] tab;

    tab = m.tab;
    m.tab = nullptr;

    return *this;
}

wektor macierz::operator[](int i) const
{
    if(i < 0 || i >= w) throw index_error();

    return *tab[i];
}

wektor& macierz::operator[](int i)
{
    if(i < 0 || i >= w) throw index_error();

    return *tab[i];
}

macierz& macierz::operator+=(const macierz &m)
{
    if(w != m.w || k != m.k) throw dimentions_error();

    for(int i=0; i<m.w; i++)
    {
        *tab[i] += m[i];
    }
    return *this;
}

macierz& macierz::operator-=(const macierz &m)
{
    if(w != m.w || k != m.k) throw dimentions_error();

    for(int i=0; i<m.w; i++)
    {
        *tab[i] -= m[i];
    }
    return *this;
}

macierz& macierz::operator*=(double d)
{
    for(int i=0; i<w; i++)
    {
        *tab[i] *= d;
    }
    return *this;
}

namespace obliczenia
{
    istream& operator>>(istream &we, macierz &m)
    {
        for(int i=0; i<m.w; i++)
        {
            we >> m[i];
        }
        return we;
    }

    ostream& operator<<(ostream &wy, const macierz &m)
    {
        for(int i=0; i<m.w; i++)
        {
            wy << m[i] << '\n';
        }

        return wy;
    }

    macierz operator-(const macierz &m)
    {
        macierz wynik = m;

        for(int i=0; i<wynik.w; i++)
        {
            wynik[i] *= -1;
        }

        return wynik;
    }

    macierz operator+(const macierz &p, const macierz &q)
    {
        if(p.w != q.w || p.k != q.k) throw dimentions_error();

        macierz wynik = p;

        for(int i=0; i<q.w; i++)
        {
            wynik[i] += q[i];
        }

        return wynik;
    }

    macierz operator-(const macierz &p, const macierz &q)
    {
        if(p.w != q.w || p.k != q.k) throw dimentions_error();

        macierz wynik = p;

        for(int i=0; i<q.w; i++)
        {
            wynik[i] -= q[i];
        }

        return wynik;
    }

    macierz operator*(const macierz &m, double d)
    {
        macierz wynik = m;

        for(int i=0; i<m.w; i++)
        {
            wynik[i] *= d;
        }

        return wynik;
    }

    macierz operator*(double d, const macierz &m)
    {
        macierz wynik = m;

        for(int i=0; i< m.w; i++)
        {
            wynik[i] *= d;
        }

        return wynik;
    }

    macierz operator*(const macierz &p, const macierz &q)
    {
        if(p.k != q.w) throw dimentions_error();

        macierz wynik = macierz(p.w, q.k);

        for(int i=0; i<p.w; i++)
        {
            for(int j=0; j<q.k; j++)
            {
                wynik[i][j] = p[i] * (~q)[j];
            }
        }

        return wynik;
    }

    macierz operator~(const macierz &m)
    {
        macierz wynik = macierz(m.k, m.w);

        for(int i=0; i<m.w; i++)
        {
            for(int j=0; j<m.k; j++)
            {
                wynik[j][i] = m[i][j];
            }
        }

        return wynik;
    }
}
