#include <bits/stdc++.h>
using namespace std;
#define maxn 500010
int n, s, ans = 0x7fffffff, far;
int dis[maxn], fa[maxn], flag[maxn];
struct edge{
    int to, w;
};
vector<edge> G[maxn];
void dfs(int u, int f){
    fa[u] = f;
    if (dis[u] > dis[far]) far = u;
    for (int i = 0; i < G[u].size(); ++i){
        int v = G[u][i].to, w = G[u][i].w;
        if (v == f || flag[v]) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}
void addedge(int u, int v, int w){
    G[u].push_back((edge{v, w}));
    G[v].push_back((edge{u, w}));
}
int main(){
    cin >> n >> s;
    for (int i = 1; i < n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    int A, B;
    dis[1] = 1; dfs(1, 0); A = far;
    dis[far] = 0; dfs(far, 0); B = far;
    for (int i = B, j = B; i; i = fa[i]){
        while (dis[j] - dis[i] > s){
            j = fa[j];
        }
        int x = max(dis[B] - dis[j], dis[i]);
        ans = min(ans, x);
    }
    for (int i = B; i; i = fa[i]){
        flag[i] = 1;
    }
    for (int i = B; i; i = fa[i]){
        dis[i] = 0;
        dfs(i, fa[i]);
    }
    for (int i = 1; i <= n; ++i) ans = max(ans, dis[i]);
    cout << ans << endl;    
    return 0;
}
