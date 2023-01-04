#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int head[maxn], nxt[maxn << 1], to[maxn << 1], tot = 1;
void addedge(int  u, int v){
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    to[++tot] = u;
    nxt[tot] = head[v];
    head[v] = tot;
}
int dfn[maxn], low[maxn], st[maxn], top;
int cnt, deg[maxn], idx;
vector<int> vdcc[maxn];
void dfs(int u, int lst){
    low[u] = dfn[u] = ++cnt;
    st[++top] = u;
    for (int i = head[u]; i; i = nxt[i])
        if (i != (lst ^ 1)){
            int v = to[i], vv;
            if (!dfn[v]){
                dfs(v, i);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]){
                    ++idx;
                    vdcc[idx].push_back(u);
                    ++deg[u];
                    do{
                        vv = st[top--];
                        vdcc[idx].push_back(vv);
                        ++deg[vv];
                    }while (vv != v);
                }
            }else
                low[u] = min(low[u], dfn[v]);
        }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i){
        scanf("%d%d", &u, &v); addedge(u, v);
    }
    for (int i = 1; i <= n; ++i){
        if (!dfn[i]){
            dfs(i, -1);
            top = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += deg[i] > 1;
    printf("%d\n", ans);
    for (int i = 1, lst = 0; i <= n; ++i){
        if (deg[i] > 1){
            if (lst) putchar(' ');
            lst = true;
            printf("%d", i);
        }
    }
    putchar('\n');
    //每个点连通分量所对应的点
    /*
    for (int i = 1; i <= idx; ++i){
        printf("%d :", i);
        for (int j = 0; j < vdcc[i].size(); ++j){
            printf(" %d", vdcc[i][j]);
        }
        putchar('\n');
    }
    */
    return 0;
}