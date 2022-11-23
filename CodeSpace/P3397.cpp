#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010
int d[MAXN][MAXN];
int n, m, X1, Y1, X2, Y2;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> X1 >> Y1 >> X2 >> Y2;
        d[X1][Y1]++;
        d[X1][Y2 + 1]--;
        d[X2 + 1][Y1]--;
        d[X2 + 1][Y2 + 1]++;
    }
    for (int i = 1; i <= n; ++i, cout << endl){
        for (int j = 1; j <= n; ++j){
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            cout << d[i][j] << " ";
        }
    }
    return 0;
}