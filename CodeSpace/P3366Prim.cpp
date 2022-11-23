#include <bits/stdc++.h>
#define maxn 400500
using namespace std;
int head[maxn], val[maxn], to[maxn], nxt[maxn], dis[maxn], cnt, tot, ans;
bool vis[maxn];
int n, m;
void addedge(int u, int v, int w){
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
void prim(){
    for (int i = 0; i <= n; ++i){dis[i] = 2147483647;}
    dis[1] = 0; 
    while(true){
        int u = 0;
        for (int i = 1; i <= n; ++i){
            if (!vis[i] && dis[i] < dis[u]) u = i;
        }
        if (!u) break;
        tot++; vis[u] = 1; ans += dis[u];
        for (int i = head[u]; i; i = nxt[i]){
             int v = to[i];
             dis[v] = min(dis[v], val[i]);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; ++i){
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    prim();
    if (tot == n) printf("%d", ans);
    else puts("orz");
    return 0;
}