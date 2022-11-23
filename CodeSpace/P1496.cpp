#include<bits/stdc++.h>
using namespace std;
#define maxn 40001
typedef long long ll;
ll ans;
int a[maxn], b[maxn], d[maxn], c[maxn], l[maxn], f[maxn];
int n, len, dtop, ctop, x, y;
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i] >> b[i];
        d[++dtop] = a[i];
        d[++dtop] = b[i];
    }
    sort (d + 1, d + dtop + 1);
    for (int i = 1; i <= dtop; ++i){
        if (d[i] != d[i - 1] || i == 1) c[++ctop] = d[i];
    }
    for (int i = 1; i <= n; ++i){
        x = lower_bound(c + 1, c + ctop + 1, a[i]) - c;
        y = lower_bound(c + 1, c + ctop + 1, b[i]) - c;
        for (int j = x; j < y; ++j){
            f[j] = 1;
        }
    }
    for (int i = 1; i < ctop; ++i){
        if (f[i]) ans += c[i + 1] - c[i];
    }
    cout << ans << endl;
    return 0;
}