#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define R register
#define maxn 1000010
ll n, k, m;
ll loc[maxn], f[maxn], fs[maxn], ans[maxn];
//f储存这个点距离第k近的是哪个
int main(){
    cin >> n >> k >> m;
    for (R ll i = 1; i <= n; ++i){cin >> loc[i];}
    f[1] = k + 1;
    ll l = 1, r = k + 1;
    for (R ll i = 2; i <= n; ++i){//找这个数周围第k近的数字，模板
        while (r + 1 <= n && loc[i] - loc[l] > loc[r + 1] - loc[i]) l++, r++;
        if (loc[i] - loc[l] >= loc[r] - loc[i]) f[i] = l;
        else f[i] = r;
    }   
    for (R ll i = 1; i <= n; ++i) ans[i] = i;
    while (m){
        memcpy(fs, f, sizeof(fs));
        if (m & 1) for (R ll i = 1; i <= n; ++i) ans[i] = f[ans[i]];
        m >>= 1;
        for (R ll i = 1; i <= n; ++i) f[i] = fs[fs[i]];
    }
    for (R ll i = 1; i <= n; ++i) cout << ans[i] << " ";
    return 0;
}       