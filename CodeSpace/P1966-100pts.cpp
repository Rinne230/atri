#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
typedef long long ll;
struct Node{
    ll val, loc;
};
Node a[maxn], b[maxn];
ll c[maxn], t[maxn];
ll n, mod = 1e8 - 3, ans;
bool cmp(Node x, Node y){return x.val < y.val;}
void mergesort(ll *c, int l, int r){
    if (l == r) return;
    int mid = (l + r) >> 1;
    mergesort(c, l, mid), mergesort(c, mid + 1, r);
    for (int i = l, j = l, k = mid + 1; i <= r; ++i){
        if (j == mid + 1){
            t[i] = c[k++];
        }else if (k == r + 1){
            t[i] = c[j++];
            ans += k - mid  - 1;
            ans %= mod;
        }else if (c[j] <= c[k]){
            t[i] = c[j++];
            ans += k - mid - 1;
            ans %= mod;
        }else{
            t[i] = c[k++];
        }
    }
    for (int i = l; i <= r; ++i){c[i] = t[i];}
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].val;
        a[i].loc = i;
    }
    for (int i = 1; i <= n; ++i){
        cin >> b[i].val;
        b[i].loc = i;
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; ++i) c[b[i].loc] = a[i].loc;
    mergesort(c, 1, n);
    cout << ans;
    return 0;
}
