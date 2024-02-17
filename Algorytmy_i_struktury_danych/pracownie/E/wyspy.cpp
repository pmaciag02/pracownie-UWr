#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, p[100], a, b, c, fx, fy, krawedz, arr[100][100];
tuple<int,int,int,int> tab[100];

bool comp(tuple<int,int,int,int> x, tuple<int,int,int,int> y){
    if(get<0>(x)==get<0>(y)){
            return get<3>(x)<get<3>(y);
    }
    return get<0>(x)<get<0>(y);
}

int Find(int x){
    while(true){
        if(p[x] == x) return x;
        x = p[x];
    }
}

void Union(int u, int v){
    p[Find(u)]=Find(v);
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = 1;
        }
    }
    // for(int i=0; i<m; i++){
    //     cin>>a>>b>>c;
    //     tab[i]=make_tuple(c, a, b, i);
    // }
    // sort(tab, tab+m, comp);

     for(int i=0; i<m; i++){
            fx=Find(get<1>(tab[i]));
            fy=Find(get<2>(tab[i]));
        if(fx!=fy){
            Union(get<1>(tab[i]),get<2>(tab[i]));
            // cout<<get<3>(tab[i])+1<<'\n';
        }
    }
}