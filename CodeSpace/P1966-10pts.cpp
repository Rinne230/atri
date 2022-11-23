#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
typedef long long ll;
struct Node{
    ll x, y;
}a[maxn];
ll n, mod = 99999997;
ll b1[maxn], b1top, c1top;
ll b2[maxn], b2top, c2top;
ll c[maxn], t[maxn], ans;
map<ll, ll> Map1, Map2;
bool cmp(Node a, Node b){return a.y < b.y;}
void mergesort(ll *p, int l, int r){
    if (l == r) return;
    int mid = (l + r) >> 1;
    mergesort(p, l, mid), mergesort(p, mid + 1, r);
    for (int i = l, j = l, k = mid + 1; i <= r; ++i){
        if (j == mid + 1){
            t[i] = p[k++];
        }else if (k == r + 1){
            t[i] = p[j++];
            ans += k - mid  - 1;
            ans %= mod;
        }else if (p[j] <= p[k]){
            t[i] = p[j++];
            ans += k - mid - 1;
            ans %= mod;
        }else{
            t[i] = p[k++];
        }
    }
    for (int i = l; i <= r; ++i){p[i] = t[i];}
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {cin >> a[i].x; b1[++b1top] = a[i].x;}
    for (int i = 1; i <= n; ++i) {cin >> a[i].y; b2[++b2top] = a[i].y;}
    sort(b1 + 1, b1 + b1top + 1);
    sort(b2 + 1, b2 + b2top + 1);
    b1[0] = -0x7ffffff;
    b2[0] = -0x7ffffff;
    for (int i = 1; i <= n; ++i){
        if (b1[i] != b1[i - 1]) Map1[b1[i]] = ++c1top;
        if (b2[i] != b2[i - 1]) Map2[b2[i]] = ++c2top;
    }
    for (int i = 1; i <= n; ++i){
        a[i].x = Map1[a[i].x];
        a[i].y = Map2[a[i].y];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i) c[i] = a[i].x;
    mergesort(c, 1, n);
    cout << ans % mod;
    return 0;
}