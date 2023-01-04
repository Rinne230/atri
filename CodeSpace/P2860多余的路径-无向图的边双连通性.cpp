#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int head[maxn], nxt[maxn << 1], to[maxn << 1], tot = 1;
void addedge(int u, int v){
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    to[++tot] = u;
    nxt[tot] = head[v];
    head[v] = tot;
}
int dfn[maxn], low[maxn], cnt, idx, bel[maxn], top, st[maxn];
void dfs(int u, int lst){
    low[u] = dfn[u] = ++cnt;
    st[++top] = u;
    for (int i = head[u]; i; i = nxt[i])
        if(i != (lst ^ 1)){
            int v = to[i];
            if (!dfn[v]){
                dfs(v, i);
                low[u] = min(low[u], low[v]);
            }else
                low[u] = min(low[u], dfn[v]);    
        }
    if (low[u] == dfn[u]){
        int v; ++idx;
        do bel[v = st[top--]] = idx; while(v != u);
    }
}
int deg[maxn];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i){
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    dfs(1, -1);
    for (int i = 2; i <= tot; i += 2){
        int u = to[i], v = to[i ^ 1];
        if (bel[u] != bel[v])
            ++deg[bel[u]], ++deg[bel[v]];
    }
    int ans = 0;
    for (int i = 1; i <= idx; ++i){
        ans += (deg[i] == 1);
    }
    ans = (ans + 1) / 2;
    printf("%d\n", ans);
    return 0;
}