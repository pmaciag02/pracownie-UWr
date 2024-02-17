#include <iostream>
#include <cstring>
#include <initializer_list>
#include <list>
#include "kolejka.hpp"



//Patryk Maciąg



using namespace std;



kolejka::kolejka() : pojemnosc(1), tab(NULL){
tab = new string[1];
}



kolejka::kolejka(int n) : pojemnosc(n), tab(NULL){
if (not n) throw invalid_argument("podano złą wartość\n");

tab = new string[n];
}



kolejka::kolejka(initializer_list<string> a) : pojemnosc(a.size()), ile(a.size()), tab(NULL){
tab = new string[pojemnosc];

initializer_list<string>::iterator it;
int i=0;
for ( it=a.begin(); it!=a.end(); ++it)
{
tab[i] = *it;
i++;
}

}





kolejka::kolejka(const kolejka &k) : pojemnosc(k.pojemnosc), tab(NULL){
tab = new string[k.pojemnosc];
poczatek = k.poczatek;
ile = k.ile;

for(int i=0; i<k.pojemnosc; i++)
{
tab[i]=k.tab[i];
}

}




kolejka::kolejka(kolejka &&k) : tab(NULL){
swap(pojemnosc, k.pojemnosc);
swap(tab, k.tab);
swap(poczatek, k.poczatek);
swap(ile, k.ile);
}





kolejka::~kolejka(){
tab = NULL;
delete[] tab;
}


const kolejka& kolejka::operator = (const kolejka &k){

if(this == &k) return *this;

this->~kolejka();
pojemnosc = k.pojemnosc;
tab = new string[pojemnosc];
poczatek = k.poczatek;
ile = k.ile;

for(int i=0; i<k.ile; i++)
{
tab[i]=k.tab[i];
}

return *this;
}





const kolejka& kolejka::operator = (kolejka &&k){
if(this == &k) return *this;

swap(pojemnosc, k.pojemnosc);
swap(tab, k.tab);
swap(poczatek, k.poczatek);
swap(ile, k.ile);

return *this;
}




void kolejka::wstaw(string s){
if(ile==pojemnosc)
{
cerr << "brak miejsca\n";
}
else
{
tab[(poczatek+ile)%pojemnosc]=s;
ile++;
}
}





string kolejka::usun(){
if(!ile) {cerr << "pusta kolejka\n"; return "";}
ile--;
string s = tab[poczatek];
poczatek=(poczatek+1)%pojemnosc;
return s;
}




string kolejka::zprzodu(){
if(!ile) {cerr << "pusta kolejka\n"; return "";}
return tab[poczatek];
}


int kolejka::dlugosc(){
return ile;
}

