#include <bits/stdc++.h>
using namespace std;
#define MAXN 20000010
typedef long long ll;
struct Node{int v, w;};
vector<Node> G[MAXN];
ll n, ans, sizep[MAXN];
void addedge(int u, int v, int w){
    G[u].push_back(Node{v, w});
    G[v].push_back(Node{u, w});
}
void dfs(int u, int fa){
    sizep[u] = 1;
    for (int i = 0; i < G[u].size(); ++i){
        int v = G[u][i].v, w = G[u][i].w;
        if (v == fa) continue;
        dfs(v, u);
        sizep[u] += sizep[v];
        ans += w * abs((sizep[v] << 1) - n);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}