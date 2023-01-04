#include <bits/stdc++.h>
#include <utility>
#define MAXN 100010
using namespace std;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot = 1;
void addedge(int u, int v){
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    to[++tot] = u;
    nxt[tot] = head[v];
    head[v] = tot;
}
pair<int, int> edge[MAXN];
//dfn   表示    dfs序
//low   表示    子树通过至少一条非树边能到达的最低深度点的dfs序
//st    表示    用来提取连通块的栈
//bel   表示    每个点属于的联通块
int dfn[MAXN], low[MAXN], st[MAXN], top;
int cnt, idx, bel[MAXN], anscnt = 0;
void dfs(int u, int lst){
    low[u] = dfn[u] = ++cnt;
    st[++top] = u;
    for (int i = head[u]; i; i = nxt[i])
        if(i != (lst ^ 1)){//因为两条边是连续存储的，所以懂得都懂
            int v = to[i];
            if (!dfn[v]){
                dfs(v, i);
                //当边是dfs树上的时候，直接取子树min
                low[u] = min(low[u], low[v]);
                //发现割边
                if (low[v] > dfn[u]) edge[anscnt++] = make_pair(min(u, v), max(u, v));
            }else
                //当边不是dfs树上的时候，更新到达的深度最低的点
                low[u] = min(low[u], low[v]);//low[u] = min(low[u], dfn[v]);
        }
    //当子树没有非树边能到达自己祖先的时候
    //自己就算连通块深度最低的点
    if (low[u] == dfn[u]){
        int v; ++idx;
        do{
            v = st[top--];
            bel[v] = idx;
        } while (v != u);
    }
}
bool cmp (pair<int, int> x, pair<int, int> y){
    if (x.first == y.first)
        return x.second < y.second;
    else 
        return x.first < y.first;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++i){
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) dfs(i, -1);
    sort(edge, edge + anscnt, cmp);
    for (int i = 0, u, v; i < anscnt; ++i){
        u = edge[i].first, v = edge[i].second;
        printf("%d %d\n", u, v);
    }
    return 0;
}