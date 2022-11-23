#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 2147483647
#define maxn 500010
int n, m, s, cnt;
int dis[maxn], to[maxn], nxt[maxn], val[maxn], head[maxn];
bool vis[maxn];
queue<int> q;
void addedge(int u, int v, int w){
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
void spfa(){
    for (int i = 1; i <= n; ++i){dis[i] = inf;}
    dis[s] = 0; vis[s] = 1; q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = nxt[i]){
            if (dis[to[i]] > (ll)dis[u] + val[i]){dis[to[i]] = (ll)dis[u] + val[i];}
            if (!vis[to[i]]){
                q.push(to[i]);
                vis[to[i]] = true;
            }
        }
    }
}
int main(){
    n = read(), m = read(), s = read();
    for (int i = 1, u, v, w; i <= m; ++i){
        u = read(), v = read(), w = read();
        addedge(u, v, w);
    }
    spfa();
    for (int i = 1; i <= n; ++i){cout << dis[i] << " ";}
    return 0;
}