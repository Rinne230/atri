#include <bits/stdc++.h>
#define maxn 4005
int n, cnt, lst[maxn], head[maxn], to[maxn << 1], val[maxn << 1], nxt[maxn << 1];
int dis[maxn], d[maxn][maxn];
bool vis[maxn];
void addedge(int u, int v, int w){
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
void prim(){
    for (int i = 0; i <= n; ++i) dis[i] = 0x7fffffff;
    dis[1] = 0;
    int tot = 0;
    while (true){
        int u = 0;
        for (int i = 1; i <= n; ++i) if (!vis[i] && dis[i] < dis[u]) u = i;
        if (!u) break;
        vis[u] = 1;
        if (u != 1){
            addedge(u, lst[u], dis[u]);
            addedge(lst[u], u, dis[u]);
        }
        for (int v = 1; v <= n; ++v){
            if (vis[v]) continue;
            int w = d[u][v];
            if(dis[v] > w){
                dis[v] = w;
                lst[v] = u;
            }
        }
    }
}

void dfs(int u, int fa){
    for (int i = head[u]; i; i = nxt[i]){
        int v = to[i], w = val[i];
        if (v == fa) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            scanf("%d", &d[i][j]);
            if (i != j && d[i][j] == 0){puts("NO"); return 0;}
            if (i == j && d[i][j] != 0){puts("NO"); return 0;}
        }
    }
    prim();
    for (int i = 1; i <= n; ++i){
        dis[i] = 0;
        dfs(i, 0);
        for (int j = 1; j <= n; ++j)
            if (dis[j] != d[i][j]) {puts("NO"); return 0;}
    }
    puts("Yes");
    return 0;
}