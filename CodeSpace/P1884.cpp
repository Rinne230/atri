#include <bits/stdc++.h>
using namespace std;
#define maxn 4010
typedef long long ll;
int n, ctop, btop;
int a[maxn][4];
int b[maxn], c[maxn];
int f[maxn][maxn];
map<int, int> Map;
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= 3; ++j){
            cin >> a[i][j];
            b[++btop] = a[i][j];
        }
    }
    sort(b + 1, b + btop + 1);
    b[0] = -0x7ffffff;
    for (int i = 1; i <= btop; ++i){
        if (b[i] != b[i - 1]) 
        c[++ctop] = b[i];
        Map[b[i]] = ctop;   
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= 3; ++j){
            a[i][j] = Map[a[i][j]];
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = a[i][0]; j < a[i][2]; ++j){
            f[j][a[i][3]]++;
            f[j][a[i][1]]--;
        }
    }
    for (int i = 1; i < ctop; ++i){
        for (int j = 1; j < ctop; ++j){
            f[i][j] += f[i][j - 1];
        }
    }
    ll ans = 0;
    for (int i = 1; i < ctop; ++i){
        for (int j = 1; j < ctop; ++j){
            if (f[i][j]) ans += (ll)(c[i + 1] - c[i]) * (c[j + 1] - c[j]);
        }
    }
    cout << ans << endl;
}