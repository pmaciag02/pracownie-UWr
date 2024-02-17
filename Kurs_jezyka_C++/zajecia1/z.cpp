#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <limits.h>
using namespace std;


//Patryk Maciąg, 331542


vector<int64_t> rozklad(int64_t n)
{
    vector<int64_t> v;
    int64_t p=sqrt(abs(n)), k=2;
    while(abs(n)!= 1 && k<=p)
    {
        while(!(n%k))
        {
            v.push_back(k);
            n/=k;
        }
        k++;
    }
    if(abs(n)>1) v.push_back(abs(n));
    return v;
}



int main(int argc, char *argv[])
{

if(argc==1)
{
cerr << "./z1 a1 a2 a3 ... an\n";
return 0;
}

for(int i=1; i<argc; i++)
{
    int64_t x=stoll(argv[i]);
    cout << x << "=";
   if(x<0) {cout << -1 << "*";}
   bool mult=0;
 if(x==LLONG_MIN)
 {
 cout<<2;
 mult=1;
 x/=2;
 }
    vector<int64_t> wspolczynniki = rozklad(x);
    if(wspolczynniki.empty()) wspolczynniki.push_back(abs(x));

    for(int64_t j: wspolczynniki)
    {
        if(mult)
        {
        cout << '*' << j;
        }
        else
        {
        cout << j;
        mult=1;
        }
    }
    cout << "\n";
}



return 0;
}



