#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> G[maxn << 1];
int n, k, far, dis[maxn], fa[maxn], tmp[maxn], maxdis[maxn];
int ans = 0;
void addedge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
bool cmp(int a, int b){return a > b;}
void dfs(int u, int f){
    fa[u] = f;
    if (dis[u] > dis[far]) far = u;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if (v == f) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}
void dfs_k(int u, int f){
    maxdis[u] = dis[u];
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if (v == f) continue;
        dis[v] = dis[u] + 1;
        dfs_k(v, u);
        maxdis[u] = max(maxdis[u], maxdis[v]);
    }
}
int main(){
    cin >> n >> k;
    for (int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        addedge(u, v);
    }
    int A, B;
    dis[1] = 1; dfs(1, 0); A = far;
    dis[far] = 0; dfs(far, 0); B = far;
    int mid = B;
    for (int i = 1; i <= (dis[B] - dis[A] + 1)/ 2; ++i) mid = fa[mid];
    memset(dis, 0, sizeof(dis));
    dfs_k(mid, 0);
    for (int i = 1; i <= n; ++i) tmp[i] = maxdis[i] - dis[i];
    sort(tmp + 1, tmp + n + 1, cmp);
    for (int i = k + 1; i <= n; ++i){
        ans = max(ans, tmp[i] + 1);
    }
    cout << ans << endl;
    return 0;
}