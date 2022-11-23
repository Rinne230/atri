#include <bits/stdc++.h>
#define maxn 200007
#define maxm 500007
#define ef(i, u) for (int i = head[(u)]; i; i = nxt[i])
using namespace std;
typedef long long ll;
int to[maxn << 1], val[maxn << 1], nxt[maxn << 1], head[maxn], cnt;//最小生成树
int n, m, fa[maxn]; ll ans0;//fa用于kruskal算法的并查集，ans0未最小生成树的边权和
struct edge{
    int u, v, w;
    bool used;
}e[maxm];//储存原图
bool cmp(edge a, edge b){return a.w < b.w;}
void addedge(int u, int v, int w){
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
int find(int x){
    if (fa[x] != x) return fa[x] = find(fa[x]);
    return x; 
}
void kruskal(){//建最小生成树
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; ++i){
        int u = find(e[i].u), v = find(e[i].v);
        if (u == v) continue;
        ans0 += e[i].w;
        addedge(e[i].u, e[i].v, e[i].w); addedge(e[i].v, e[i].u, e[i].w);
        e[i].used = 1; fa[v] = u;
    }
}
int f[maxn][20], mx[maxn][20], mx2[maxn][20], dep[maxn];//2^i层祖先//边权最大值/边权次大值/深度
void dfs(int u){
    dep[u] = dep[f[u][0]] + 1;
    for (int i = 1; i <= 18; ++i){
        f[u][i] = f[f[u][i - 1]][i - 1];
        if(mx[u][i - 1] == mx[f[u][i - 1]][i - 1]){//如果前2^i个数的最大值等于前2^i那个数的前2^i的那个数的最大值
            mx[u][i] = mx[u][i - 1];
            mx2[u][i] = max(mx2[f[u][i - 1]][i - 1], mx2[u][i - 1]);
        }
        if (mx[u][i - 1] > mx[f[u][i - 1]][i - 1]){//如果前2^i个数的最大值大于前2^i那个数的前2^i的那个数的最大值
            mx[u][i] = mx[u][i - 1];
            mx2[u][i] = max(mx[f[u][i - 1]][i - 1], mx2[u][i - 1]);
        }
        if (mx[u][i - 1] < mx[f[u][i - 1]][i - 1]){//如果前2^i个数的最大值小于前2^i那个数的前2^i的那个数的最大值
            mx[u][i] = mx[f[u][i - 1]][i - 1];
            mx2[u][i] = max(mx2[f[u][i - 1]][i - 1], mx[u][i - 1]);
        }
    }
    ef(i, u){
        int v = to[i], w = val[i];
        if (v == f[u][0]) continue;
        f[v][0] = u; mx[v][0] = w; 
        dfs(v);
    }
}
int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 18; i >= 0; --i)
        if (dep[f[u][i]] > dep[v]) u = f[u][i];
    if (u == v) return u;
    for (int i = 18; i >= 0; --i)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
ll cal(int u, int v, int w){
    int l = lca(u, v);
    int nmx = 0, nmx2 = 0;//nmx为环里其他边的最大值，nmx2为次大值
    for (int i = 18; i >= 0; --i){
        if (dep[f[u][i]] >= dep[l]){
            if (nmx == mx[u][i]) nmx2 = max(mx2[u][i], nmx2);
            if (nmx > mx[u][i]) nmx2 = max(mx[u][i], nmx2);
            if (nmx < mx[u][i]) {
                nmx2 = max(nmx, mx2[u][i]);
                nmx = mx[u][i];
            }
            u = f[u][i];
        }
        if (dep[f[v][i]] >= dep[l]){
            if (nmx == mx[v][i]) nmx2 = max(mx2[v][i], nmx2);
            if (nmx > mx[v][i]) nmx2 = max(mx[v][i], nmx2);
            if (nmx < mx[v][i]) {
                nmx2 = max(nmx, mx2[v][i]);
                nmx = mx[v][i];
            }
            v = f[v][i];
        }//树上倍增的同时更新最大值和次大值
    }
    if (w != nmx) return ans0 - nmx + w;
    if (nmx2) return ans0 - nmx2 + w;
    return 0x7f7f7f7f7f7f7f7f;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    kruskal();
    dfs(1);
    ll ans = 0x7f7f7f7f7f7f7f7f;
    for (int i = 1; i <= m; ++i) if (!e[i].used) ans = min(cal(e[i].u, e[i].v, e[i].w), ans);
    cout << ans;
    return 0;
}