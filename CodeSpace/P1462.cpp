#include <bits/stdc++.h>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
#define ef(i, u) for (int i = head[(u)]; i; i = nxt[i])
#define maxn 10005
#define maxm 100005
#define maxc 0x3fffffff
using namespace std;
bool vis[maxn];
int cost[maxn], dis[maxn];
int head[maxn];
int to[maxm], nxt[maxm], val[maxm];
struct node{
    int pos, dis;
    friend bool operator < (node a, node b){
        return a.dis > b.dis;
    }
}tmp;
priority_queue<node> q;
int n, m, blood;
int cnt;
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
void addedge(int u, int v, int w){
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
bool spfa(int x){
    if (x < cost[1]) return false;
    f(i, 1, n) dis[i] = 1e9;
    memset(vis, false, sizeof(vis));
    dis[1] = 0;
    tmp.pos = 1; tmp.dis = 0;
    q.push(tmp);
    while(!q.empty()){
        int u = q.top().pos;
        q.pop();
        ef(i, u){
            int v = to[i];
            if (cost[v] <= x && !vis[v] && dis[u] + val[i] < dis[v]){
                dis[v] = dis[u] + val[i];
                tmp.pos = v; tmp.dis = dis[v];
                q.push(tmp);
            }
        }
    }
    if(dis[n] < blood) return true;
    return false;
}
int main(){
    n = read(), m = read(), blood = read();
    f(i, 1, n) cost[i] = read();    
    f(i, 1, m){
        int u = read(), v = read(), w = read();
        addedge(u, v, w);
        addedge(v, u, w);
    }
    if (!spfa(maxc)){
        printf("%s", "AFK");
        return 0;
    }
    int l = 1, r = maxc, mid = (l + r) >> 1;
    bool flag = false;
    while (l <= r){
        flag = spfa(mid);
        if (flag){
            r = mid - 1;
            mid = (l + r) >> 1;
        }else{
            l = mid + 1;
            mid = (l + r) >> 1;
        }
    }
    printf("%d", l);
    return 0;
}