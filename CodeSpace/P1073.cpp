#include <bits/stdc++.h>
#define f(i ,a, b) for (int i = (a); i <= (b); ++i)
#define inf 0x7fffffff
#define maxn 10005
#define maxm 100005
using namespace std;
int n, m, cnt, f[maxn], mi[maxn], cost[maxn];
vector<int> G[maxm];
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    
    return x * f;
}
void dfs(int u, int minx, int fa){
    bool flag = true;
    minx = min(minx, cost[u]);
    if (mi[u] > minx) mi[u] = minx, flag = false;
    int maxx = max(f[fa], cost[u] - minx);
    if (f[u] < maxx) f[u] = maxx, flag = false;
    if (flag) return;
    for (int i = 0; i < G[u].size(); ++i) dfs(G[u][i], minx, u);
}
int main(){
    n = read(), m = read();
    f(i, 0, maxn - 1) mi[i] = inf;
    f(i, 1, n) cost[i] = read();
    f(i, 1, m){
        int u = read(), v = read(), op = read();
        G[u].push_back(v);
        if (op == 2) G[v].push_back(u);
    }
    dfs(1, inf, 0);
    printf("%d", f[n]);
    return 0;
}