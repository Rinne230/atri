#include <bits/stdc++.h>
#define maxn 500010
using namespace std;
typedef long long ll;
ll n, m, ans;
ll a[maxn], b[maxn], c[maxn], d[maxn];
ll btop, dtop;
map<ll, ll> Map;
inline ll lowbit(int x) {return x & (-x);}
void add(int x, ll k){
    for (int i = x; i <= dtop; i += lowbit(i)) c[i] += k;
}
ll sum(int x){
    ll ret = 0;
    for (int i = x; i; i -= lowbit(i))  ret += c[i];
    return ret;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        b[++btop] = a[i]; 
    }
    sort(b + 1, b + btop + 1);
    b[0] = -0x7ffffff;
    for (int i = 1; i <= btop; ++i){
        if (b[i] != b[i - 1]){
            d[++dtop] = b[i];
            Map[b[i]] = dtop;
        }
    }
    for (int i = 1; i <= n; ++i) a[i] = Map[a[i]];
    for (int i = n; i; --i){
        ans += sum(a[i] - 1);
        add(a[i], 1);
    }
    cout << ans << endl;
    return 0;
}