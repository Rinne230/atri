#include <bits/stdc++.h>
#define maxn 500001
#define maxm 1500001
#define inf 0x3f3f3f3f
#define f(i, a, b) for (ll i = (a); i <= (b); ++i)
#define ef(i, u) for (ll i = head[(u)]; i; i = nxt[i])
using namespace std;
typedef long long ll;
int head[maxn], to[maxm], vis[maxn], val[maxm], nxt[maxm], dis[maxn], flag[maxn];
int n, k, X, A, B, cnt0;
inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
void addedge(int u, int v, int w){
    to[++cnt0] = v;
    val[cnt0] = w;
    nxt[cnt0] = head[u];
    head[u] = cnt0;
}
bool dfs(ll u){
    vis[u] = 1;
    flag[u] = 1;
    ef(i, u){
        int v = to[i];
        if (dis[v] < dis[u] + val[i]){ 
            if (vis[v]) return 1;
            dis[v] = dis[u] + val[i];
            if (dfs(v)) return 1;
        }
    }
    vis[u] = 0;
    return 0;
}
int main(){
    n = read(); k = read();
    f(i, 1, k){
        X = read(); A = read(); B = read();
        switch (X){
        case 1:
            addedge(A, B, 0);
            addedge(B, A, 0);
            break;
        case 2:
            addedge(A, B, 1);
            break;
        case 3:
            addedge(B, A, 0);
            break;
        case 4:
            addedge(B, A, 1);
            break;
        default:
            addedge(A, B, 0);
            break;
        }
    }
    bool ok = 0;
    ll sum = 0;
    f(i, 1, n){
        if (!flag[i]){
            dis[i] = 1;
            if (dfs(i)) ok = 1;
        }
    }
    f(i, 1, n) sum += dis[i];
    if(ok) printf("-1\n");
    else printf("%lld\n", sum);
    return 0;
}
