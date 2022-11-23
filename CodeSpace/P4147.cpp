#include <iostream>
using namespace std;
#define MAXN  1001
int n, m, ans = 0;
char a[MAXN][MAXN];
int h[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            h[i][j] = 1, r[i][j] = l[i][j] = j;
        }
        for (int j = 2; j <= m; ++j){
            if (a[i][j] == 'F' && a[i][j - 1] == 'F'){
                l[i][j] = l[i][j - 1];
            }
        }
        for (int j = m - 1; j >= 1; --j){
            if (a[i][j] == 'F' && a[i][j + 1] == 'F'){
                r[i][j] = r[i][j + 1];
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (i > 1 && a[i][j] == 'F'){
                if (a[i - 1][j] == 'F'){
                    h[i][j] = h[i - 1][j] + 1;
                    if (l[i - 1][j] > l[i][j]){
                        l[i][j] = l[i - 1][j];
                    }
                    if (r[i - 1][j] < r[i][j]){
                        r[i][j] = r[i - 1][j];
                    }
                }
                if ((r[i][j] - l[i][j] + 1) * h[i][j] > ans) ans = (r[i][j] - l[i][j] + 1) * h[i][j];
            }
        }
    }
    cout << 3 * ans;
    return 0;
}