#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 1010
ll a[maxn][maxn];
ll s[maxn][maxn];
ll ans = -0x7ffffff, tmp;
int n, m, c;
int ansx, ansy;
ll qsum(int X1, int Y1, int X2, int Y2){
    return s[X2][Y2] + s[X1 - 1][Y1 - 1] - s[X2][Y1- 1] - s[X1 - 1][Y2];
}
int main(){
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n - c + 1; ++i){
        for (int j = 1; j <= m - c + 1; ++j){
            int k = i + c - 1;
            int l = j + c - 1;
            tmp = ans;
            ans = max(ans, qsum(i, j, k, l));
            if (tmp != ans){
                ansx = i, ansy = j;
            }
        }
    }
    cout << ansx << " " << ansy << endl;
    return 0;
}