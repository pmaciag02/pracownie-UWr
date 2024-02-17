#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    int n, t[1000002];
    long long sum = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        sum += t[i];
    }

    int i = 0, j = 1;
    long long current_sum = t[0], maxlength = 0;
    
    while(i != n) {
        current_sum += t[j];

        if(current_sum <= sum - current_sum) {
            j++;
            j %= n;
        }
        else {
            current_sum -= t[i] + t[j];
            maxlength = max(min(current_sum + t[i], sum - current_sum - t[i]), maxlength);
            i++;
        }
    }


    
    printf("%lld\n", maxlength);

    return 0;
}