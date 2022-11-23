#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> G[maxn];
int n, m, ans, d, dis[maxn];
void addedge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int u, int fa){
    if (dis[u] <= d) ans++;
    for (int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if (v == fa) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}
int main(){
    cin >> n >> d;
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        addedge(u, v);
    }
    dfs(1, 0);
    cout << ans - 1 << endl;
    return 0;
}