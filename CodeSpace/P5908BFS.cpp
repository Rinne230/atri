#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> G[maxn];
queue<int> Q;
int n, d, ans, dis[maxn], fa[maxn];
void addedge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
void bfs(int u){
    Q.push(u);
    while (!Q.empty()){
        int u = Q.front(); Q.pop();
        if (dis[u] <= d) ans++;
        for (int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if (v == fa[u]) continue;
            fa[v] = u;
            dis[v] = dis[u] + 1;
            Q.push(v);
        }
    }
}
int main(){
    cin >> n >> d;
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        addedge(u, v);
    }
    bfs(1);
    cout << ans - 1 << endl;
    return 0;
}