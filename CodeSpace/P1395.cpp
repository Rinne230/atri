#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int inf = 0x7fffffff;
int f[maxn], dep[maxn], sizep[maxn];
int n, center, sum = 0; 
vector<int> G[maxn];
queue<int> q;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
void getcenter(int u, int fa){
    sizep[u] = 1, f[u] = 0;
    for (int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if (v == fa) continue;
        getcenter(v, u);
        sizep[u] += sizep[v];
        f[u] = max(f[u], sizep[v]);//f数组存储该点下的最大子树
    }
    f[u] = max(f[u], n - sizep[u]);
    if (f[u] < f[center] || (f[u] == f[center] && u < center)) center = u;
}
void bfs(){
    q.push(center);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if (dep[v] || v == center) continue;
            dep[v] = dep[u] + 1;
            sum += dep[v];
            q.push(v);
        }
    }
}
void addedge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
int main(){
    n = read();
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        addedge(u, v);
    }
    center = 0;
    f[0] = inf;
    getcenter(1, 0);
    bfs();
    cout << center << " " << sum << endl;
    return 0;
}