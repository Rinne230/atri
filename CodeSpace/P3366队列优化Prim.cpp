#include <bits/stdc++.h>
#define inf 0x7fffffff
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
struct node{
    int pos, dis;
    friend bool operator <(node a, node b){
        return a.dis > b.dis;
    }
}tmp;
priority_queue<node> q;
void prim(){
    for (int i = 1; i <= n; ++i) dis[i] = inf;
    dis[1] = 0;
    tmp.dis = 0; tmp.pos = 1; q.push(tmp);
    while (!q.empty()){
        tmp = q.top(); q.pop();
        int u = tmp.pos;
        if (vis[u]) continue;
        vis[u] = 1; tot++; ans += dis[u];
        for (int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            dis[v] = min(dis[v], val[i]);
            tmp.dis = dis[v]; tmp.pos = v;
            q.push(tmp);
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