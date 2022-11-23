#include <bits/stdc++.h>
using namespace std;
#define inf 2147483647
#define maxn 2500010
typedef long long ll;
int n, m, k, s, t, cnt;
ll dis[maxn], to[maxn], nxt[maxn], val[maxn], head[maxn];
bool vis[maxn];
struct node{
    int v, w;
    friend bool operator < (node a, node b){
        return a.w > b.w;
    }
}tmp;
priority_queue<node> q;
void addedge(int u, int v, ll w){
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
void Dijkstra(){
    for (int i = 0; i <= (k + 1) * n; ++i) dis[i] = inf;
    dis[s] = 0;
    tmp.v = s; tmp.w = 0; q.push(tmp);
    while (!q.empty()){
        int u = q.top().v;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i]){
            if (dis[to[i]] > (ll)dis[u] + val[i]) {
                dis[to[i]] = (ll)dis[u] + val[i];
                tmp.w = dis[to[i]]; tmp.v = to[i]; q.push(tmp);
            }
        }
    }
}
int main(){
    n = read(), m = read(), k = read();
    s = read(), t = read();
    for (int i = 1, u, v, w; i <= m; ++i){
        u = read(), v = read(), w = read();
        addedge(u, v, w);
        addedge(v, u, w);
        for (int j = 1; j <= k; ++j){
            addedge(u + j * n, v + j * n, w);
            addedge(v + j * n, u + j * n, w);
            addedge(u + j * n - n, v + j * n, 0);
            addedge(v + j * n - n, u + j * n, 0);
        }
    }
    Dijkstra();
    ll ans = inf;
    for (int i = 0; i <= k; ++i)
        ans = min(ans, dis[t + i * n]);
    printf("%lld", ans);
    return 0;
}