#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e5 + 100;
struct Node{
    ll w;
    int x, y;//x的第y大
    bool operator<(const Node & A) const {
        return w < A.w;
    }
}d[maxn];
int n, k;
ll a[maxn], s[maxn], sz[maxn * 32], tot = 0;;
struct trie{
    int ch[2];
}t[maxn * 32];
priority_queue<Node> q;//结构体内重载小于号，大根堆

void insert(ll val, int x){
    for (int i = 31; i >= 0; --i){
        bool c = (val >> i) & 1;
        if (!t[x].ch[c]){
            t[x].ch[c] = ++tot;
        }
        x = t[x].ch[c];
        sz[x]++;//子节点数
    }
}

ll find(ll val, int x, int tmp){//tmp作为要找的第几大
    ll s = 0;
    for (int i = 31; i >= 0; --i){
        bool c = (val >> i) & 1;//最高位开始取，判断是否为1
        if (sz[t[x].ch[!c]] >= tmp){
            x = t[x].ch[!c];
            s += (1ll << i);
        }else{
            tmp -= sz[t[x].ch[!c]];
            x = t[x].ch[c];
        }
    }
    return s;
}
int main(){
    cin >> n >> k;
    for (ll i = 1;i <= n; ++i){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    for (int i = 0; i <= n; ++i){
        insert(a[i], 0);
    }
    for (int i = 0; i <= n; ++i){
        d[i].w = find(a[i], 0, 1);
        d[i].x = i;
        d[i].y = 1;
        q.push(d[i]);
    }
    ll ans = 0;
    Node A;
    for (int i = 1; i <= (k << 1); ++i){
        A = q.top();
        ans += A.w;
        q.pop();
        d[A.x].y++;
        d[A.x].w = find(a[A.x], 0, d[A.x].y);
        q.push(d[A.x]);
    }
    ans >>= 1;
    cout << ans << endl;
}