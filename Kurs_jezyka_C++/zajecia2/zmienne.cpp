#include <iostream>
#include "zmienne.hpp"

using namespace std;


zmienna::zmienna():zmienna("_", 0){
}

zmienna::zmienna(string a, double b) : nazwa(a), wartosc(b){
//nazwa=a; wartosc=b;
}

zmienna::zmienna(string a) : nazwa(a), wartosc(0){
//nazwa=a; wartosc=0;
}

zmienna::~zmienna(){
}

string zmienna::get_nazwa(){
return nazwa;
}

void zmienna::set_wartosc(double b){
wartosc = b;
}

double zmienna::get_wartosc(){
return wartosc;
}

zbior_zmiennych::zbior_zmiennych(const int a) : n(a), tab(NULL){
if(n>=0)
{
tab = new zmienna[n];
}
else
{
throw invalid_argument( "podano złą wartość\n" );
}
}

zbior_zmiennych::~zbior_zmiennych(){
tab = NULL;
delete [] tab;
}

bool zbior_zmiennych::sprawdz(string a){
for(int i=0; i<n; i++)
{
if(tab[i].get_nazwa()==a) return true;
}
return false;
}

void zbior_zmiennych::set_zmienna(zmienna a){
if(!zbior_zmiennych::sprawdz(a.get_nazwa()))
{
int i;
for(i=0; i<n; i++)
{
if(tab[i].get_nazwa()=="_")
{
tab[i]=a;
break;
}
}
if(i==n) cerr << "brak miejsca w tablicy\n";
}
}

double zbior_zmiennych::get_zmienna(string a){
int i;
for(i=0; i<n; i++)
{
if(tab[i].get_nazwa()==a) break;

}
if(i==n)
{
cerr << "brak zmennej <" << a << "> w zbiorze, zwrócono wartość 0\n";
return 0;
}
return tab[i].get_wartosc();
}

void zbior_zmiennych::delete_zmienna(string a){
for(int i=0; i<n; i++)
{
if(tab[i].get_nazwa()==a)
{
tab[i]=zmienna();
}
}
}

void zbior_zmiennych::modyfikacja(string a, double b){
int i;
for(i=0; i<n; i++)
{
if(tab[i].get_nazwa()==a)
{
tab[i].set_wartosc(b);
break;
}
}
if(i==n)
{
cerr << "brak zmennej <" << a << "> w zbiorze\n";
}
}
