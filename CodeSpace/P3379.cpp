//倍增求LCA
//author:atrilactose
#include <bits/stdc++.h>
using namespace std;
#define maxn 500001
int n, m, S;
int d[maxn], f[20][maxn];
vector<int> G[maxn];
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
void addedge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int u, int fa){
    for (int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if (v == fa) continue;
        d[v] = d[u] + 1;
        f[0][v] = u;
        dfs(v, u);
    }
}
void init(){
    for (int i = 1; i <= 18; ++i){
        for (int j = 1; j <= n; ++j){
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
}
int LCA(int u, int v){
    if (d[u] < d[v]) swap(u, v);
    for (int i = 18; i >= 0; --i){
        if (d[f[i][u]] >= d[v])
            u = f[i][u];
    }
    if (u == v) return u;
    for (int i = 18; i >= 0; --i){
        if (f[i][u] != f[i][v]){
            u = f[i][u], v = f[i][v];
        }
    }
    return f[0][u];
}
int main(){
    n = read(), m = read(), S = read();
    for (int i = 1; i < n; ++i){
        int u = read(), v = read();
        addedge(u, v);
    }
    d[S] = 1; dfs(S, 0);
    init();
    while(m--){
        int u = read(), v = read();
        printf("%d\n", LCA(u, v));
    }
}