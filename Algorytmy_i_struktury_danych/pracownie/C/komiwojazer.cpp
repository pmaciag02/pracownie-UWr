#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000000000000000

using namespace std;

// int shift_int(int v, int d) {
//     return (v << 14) + d;
// }

int main()
{
    int n, m, k, a, b, c, x, d, v, cost;
    long long dist[100002];
    priority_queue <pair<long long, int>> Q;
    //vector <pair<int, int>> graph[100002];
    vector <int> graph[100002];
    bool visited[100002];


    scanf("%d %d %d", &n, &m, &k);
    getchar();

    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        getchar();
        graph[a].push_back((b << 14) + c);
        graph[b].push_back((a << 14) + c);

        // int test1 = (a << 14) + c, test2= (a << 14) + c;
        // printf("a = %d, c = %d, test1a = %d, test1c = %d\n", a, c, test1 >> 14, test1 & 16383);

    }
    dist[1] = 0;
    for(int i = 2; i <= n; i++){
        dist[i] = INF;
    }

    Q.push(make_pair(0, -1));
    visited[1] = true;

    while(!Q.empty()){
        x = Q.top().second * -1;
        d = Q.top().first * -1;
        Q.pop();
        if(d > dist[x]) continue;

        for(int i = 0; i < graph[x].size(); i++){
            // v = graph[x][i].first;
            // cost = graph[x][i].second;

            v = graph[x][i] >> 14;
            cost = graph[x][i] & 16383;

            visited[v] = true;
            if(dist[v] > d + cost){
                dist[v] = d + cost;
                Q.push(make_pair(dist[v] * -1, v * -1));
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     if(visited[i]){
    //         printf("%ld ", dist[i]);
    //     }else{
    //         printf("-1 ");
    //     }
    // }
    int city;
    long long ans = 0;
    bool nosolution = false;
    for(int i = 0; i < k; i++){
        scanf("%d", &city);
        getchar();

        if(dist[city] == INF) {
            nosolution = true;
            // printf("nie %d\n", city);
        }
        else {
            ans += 2 * dist[city];
        }
    }
    (nosolution) ? printf("NIE\n") : printf("%ld\n", ans);
    return 0;
}