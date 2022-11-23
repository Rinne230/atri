#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n;
typedef long long ll;
int a[maxn], w[maxn << 2];
int b[maxn], btop, c[maxn], ctop;
map<int, int> Map;
void init_Hash(){
    sort(b + 1, b + btop + 1);
    b[0] = -0x7ffffff;
    for (int i = 1; i <= n; ++i){
        if (b[i] != b[i - 1]){
            c[++ctop] = b[i];
            Map[b[i]] = ctop;
        }
    }
    for (int i = 1; i <= n; ++i) a[i] = Map[a[i]];
    return;
}   
int query(int u, int l, int r, int v){
    if (w[u] == 0) return 0;
    if (l >= v) return w[u];
    int m = (l + r) >> 1;
    if (m < v) return query(u << 1 | 1, m + 1, r, v);//如果左子树右端点M比v小，那么所求的一定是右子树的某个子区间
    else return query(u << 1, l, m, v) + query(u << 1 | 1, m + 1, r, v);
}
void update(int u, int l, int r, int v){
    ++w[u];//经过的区间一定包含v因此直接自增即可
    if (l == r) return;
    int m = (l + r) >> 1;
    if (m >= v) update(u << 1, l, m, v);//如果左子树右端点不小于v，则v一定在左子树中 （因为处理过程中保证了l <= v）
    else update(u << 1 | 1, m + 1, r, v);
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        b[++btop] = a[i];
    }
    init_Hash();//离散化
    
    ll ans = 0;
    for (int j = 1; j <= n; ++j){
        ans += query(1, 1, n, a[j] + 1);
        update(1, 1, n, a[j]);
    }
    cout << ans << endl;
}