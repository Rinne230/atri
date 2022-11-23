#include <bits/stdc++.h>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
#define _f(i, a, b) for (int i = (a); i >= (b); --i)
#define ef(i, u) for (int i = head[(u)]; i; i = nxt[i])
#define maxn 200010
#define inf 2147483647
using namespace std;
typedef long long ll;
int dis[2][maxn], head[maxn], cnt[maxn], to[maxn], val[maxn], nxt[maxn];
int cnt0, n, m;
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
void addedge(int u, int v, int w){
    to[++cnt0] = v;
    val[cnt0] = w;
    nxt[cnt0] = head[u];
    head[u] = cnt0;
}
struct node{
    int pos, dis;
    friend bool operator <(node a, node b){return a.dis > b.dis;}
}tmp;
priority_queue<node> q;
void Dijkstra(){
    f(i, 1, n) dis[0][i] = dis[1][i] = inf;
    dis[0][1] = 0;
    tmp.dis = 0;
    tmp.pos = 1;
    q.push(tmp);
    while (!q.empty()){
        tmp = q.top();
        q.pop();
        int u = tmp.pos, d = tmp.dis;
        if (d > dis[1][u]) continue;
        ef(i, u){
            int v = to[i], w = val[i];
            if (dis[0][v] > d + w){
                dis[1][v] = dis[0][v];
                tmp.dis = dis[0][v] = d + w;
                tmp.pos = v;
                q.push(tmp);
            }
            if (dis[1][v] > d + w && dis[0][v] < d + w){
                tmp.dis = dis[1][v] = d + w;
                tmp.pos = v;
                q.push(tmp);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    f(i, 1, m){
        int u = read(), v = read(), w = read();
        addedge(u, v, w);
        addedge(v, u, w);
    }
    Dijkstra();
    printf("%d", dis[1][n]);
}