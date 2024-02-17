#include <cstdio>
#include <algorithm>

using namespace std;

long long power(char k){
    if (k == '0') return 1;
    if (k == '1') return 7;
    if (k == '2') return 49;
    if (k == '3') return 343;
    if (k == '4') return 2401;
    if (k == '5') return 16807;
    if (k == '6') return 117649;
    if (k == '7') return 823543;
    if (k == '8') return 5764801;
    if (k == '9') return 40353607;
    return 0;
}





int main(){

    int w, k;
    char arrin[3][10002];
    long long arrdp[3][10002] = {0};
    bool visited[3][10002] = {false};
    scanf("%d %d", &w, &k);
    getchar();
    fgets(arrin[0], k+2, stdin);
    fgets(arrin[1], k+2, stdin);
    fgets(arrin[2], k+2, stdin);

    for(int i = 0; i < k; i++) {
        arrdp[0][i] = power(arrin[0][i]);
        visited[0][i] = true;
    }

    
    for(int i = 2; i < w - 1; i++) {
        
        for(int j = 0; j < k; j++) {
            if(j > 0 && j < k-1) {
                if(visited[0][j-1] && visited[0][j+1]) {
                    arrdp[2][j] = power(arrin[2][j]) + max(arrdp[0][j-1], arrdp[0][j+1]);
                    visited[2][j] = true;
                }
                else if(visited[0][j-1]) {
                    arrdp[2][j] = power(arrin[2][j]) + arrdp[0][j-1];
                    visited[2][j] = true;
                }
                else if(visited[0][j+1]) {
                    arrdp[2][j] = power(arrin[2][j]) + arrdp[0][j+1];
                    visited[2][j] = true;
                }
            }
            else if(j > 0 && visited[0][j-1]) {
                arrdp[2][j] = power(arrin[2][j]) + arrdp[0][j-1];
                visited[2][j] = true;
            }
            else if(visited[0][j+1]) {
                arrdp[2][j] = power(arrin[2][j]) + arrdp[0][j+1];
                visited[2][j] = true;
            }
        }

        for(int j = 0; j < k; j++) {
            if(j > 1 && j < k-2) {
                if(visited[2][j-2] && visited[2][j+2]) {
                    arrdp[1][j] = max(arrdp[1][j], power(arrin[1][j]) + max(arrdp[2][j-2], arrdp[2][j+2]));
                    visited[1][j] = true;
                }
                else if(visited[2][j-2]) {
                    arrdp[1][j] = max(arrdp[1][j], power(arrin[1][j]) + arrdp[2][j-2]);
                    visited[1][j] = true;
                }
                else if(visited[2][j+2]) {
                    arrdp[1][j] = max(arrdp[1][j], power(arrin[1][j]) + arrdp[2][j+2]);
                    visited[1][j] = true;
                }
            }
            else if(j > 1 && visited[2][j-2]) {
                arrdp[1][j] = max(arrdp[1][j], power(arrin[1][j]) + arrdp[2][j-2]);
                visited[1][j] = true;
            }
            else if(visited[2][j+2]){
                arrdp[1][j] = max(arrdp[1][j], power(arrin[1][j]) + arrdp[2][j+2]);
                visited[1][j] = true;
            }
        }

        // for(int i = 0; i < 3; i++) {
        //     for(int j = 0; j < k; j++) {
        //         printf("%d ", arrdp[i][j]);
        //     }
        //     putchar('\n');
        // }
        // putchar('\n');

        for(int j = 0; j < k; j++) {
            arrdp[0][j] = arrdp[1][j];
            arrdp[1][j] = arrdp[2][j];
            arrin[0][j] = arrin[1][j];
            arrin[1][j] = arrin[2][j];
            visited[0][j] = visited[1][j];
            visited[1][j] = visited[2][j];
            visited[2][j] = false;
        }

        fgets(arrin[2], k+2, stdin); 
    }

    for(int j = 0; j < k; j++) {
            if(j > 0 && j < k-1) {
                if(visited[0][j-1] && visited[0][j+1]) {
                    arrdp[2][j] = power(arrin[2][j]) + max(arrdp[0][j-1], arrdp[0][j+1]);
                    visited[2][j] = true;
                }
                else if(visited[0][j-1]) {
                    arrdp[2][j] = power(arrin[2][j]) + arrdp[0][j-1];
                    visited[2][j] = true;
                }
                else if(visited[0][j+1]) {
                    arrdp[2][j] = power(arrin[2][j]) + arrdp[0][j+1];
                    visited[2][j] = true;
                }
            }
            else if(j > 0 && visited[0][j-1]) {
                arrdp[2][j] = power(arrin[2][j]) + arrdp[0][j-1];
                visited[2][j] = true;
            }
            else if(visited[0][j+1]) {
                arrdp[2][j] = power(arrin[2][j]) + arrdp[0][j+1];
                visited[2][j] = true;
            }
        }

        
    
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < k; j++) {
    //         printf("%d ", arrdp[i][j]);
    //     }
    //     putchar('\n');
    // }

    long long result = 0;
    for(int i = 0; i < k; i++) {
        if(visited[2][i]) result = max(result, arrdp[2][i]);
    }
    
    printf("%lld\n", result);
    
    return 0;
}