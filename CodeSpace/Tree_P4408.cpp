#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
typedef long long ll;
ll n, k, far, ans, dis[maxn], fa[maxn], flag[maxn];
inline int read(){
    char ch = getchar(); int x = 0, f = 1;
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
struct edge{
    int v, w;
};
vector<edge> G[maxn << 1];
void addedge(int u, int v, int w){
    G[u].push_back(edge{v, w});
    G[v].push_back(edge{u, w});
}
void dfs(int u, int f){
    fa[u] = f;
    if(dis[u] > dis[far]) far = u;
    for (int i = 0; i < G[u].size(); ++i){
        int v = G[u][i].v, w = G[u][i].w;
        if (v == f) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }    
}
int findLCA(int u){//与直径端点的公共祖先一定在直径上
    int f = fa[u];
    while (!flag[f]){
        f = fa[f];
    }
    return f;
}
int main(){
    n = read(), k = read();
    for (int i = 1, u, v, w; i <= k; ++i){
        u = read(), v = read(), w = read();
        addedge(u, v, w);
    }
    int A, B;
    dis[1] = 1; dfs(1, 0); A = far;
    dis[far] = 0; dfs(far, 0); B = far;
    for (int i = B; i; i = fa[i]){flag[i] = 1;}
    for (int i = 1, l; i <= n; ++i){
        if(!flag[i]){
            l = findLCA(i);
            ans = max(min(dis[l], dis[B] - dis[l]) + dis[B] + dis[i] - dis[l], ans);
        }
    }
    for (int i = fa[B]; fa[i]; i = fa[i]){
        ans = max(ans, dis[B] + min(dis[i], dis[B] - dis[i]));
    }
    cout << ans << endl;
    return 0;
}