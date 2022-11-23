#include<bits/stdc++.h>
using namespace std;
#define inf 0x7fffffff
#define maxn 500010
typedef long long ll;
struct edge{
    int nxt, to, w;
}node[maxn];
int cnt, head[maxn], n, m, s, dis[maxn], vis[maxn];
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
void addedge(int u, int v, int w){
    node[++cnt].to = v;
    node[cnt].w = w;
    node[cnt].nxt = head[u];
    head[u] = cnt;
}
void Dijkstra(){
    for (int i = 1; i <= n; ++i){
        dis[i] = inf;
    }
    dis[s] = 0;
    dis[0] = inf;
    while(true){
        int u = 0;
        for (int i = 1; i <= n; ++i) u =(!vis[i] && dis[u] > dis[i]) ? i : u;
        if (u == 0) break;
        vis[u] = 1;
        for (int i = head[u]; i; i = node[i].nxt) dis[node[i].to] = dis[node[i].to] > dis[u] + node[i].w ? dis[u] + node[i].w : dis[node[i].to];   
    }    
}
int main(){
    n = read(), m = read(), s = read();
    for (int i = 1, u, v, w; i <= m; ++i){
        u = read(), v = read(), w = read();
        addedge(u, v, w);
    }
    Dijkstra();
    for (int i = 1; i <= n; ++i) cout << dis[i] << " ";
    return 0;
}