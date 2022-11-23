#include <bits/stdc++.h>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
#define _f(i, a, b) for (int i = (a); i >= (b); --i)
#define ef(i, u) for (int i = head[(u)]; i; i = nxt[i])
#define maxn 50005
#define inf 2147483647
using namespace std;
typedef long long ll;
int dis[maxn], vis[maxn], head[maxn], cnt[maxn], to[maxn], val[maxn], nxt[maxn];
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
bool spfa(){
    queue<int> q;
    f(i, 1, n){
        dis[i] = inf;
        vis[i] = 0;
    }
    q.push(1);
    dis[0] = 0;
    vis[0] = 1;
    cnt[0]++;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        ef(i, u){
            int v = to[i];
            if (dis[v] > (ll)dis[u] + val[i]){
                dis[v] = dis[u] + val[i];
                if (!vis[v]){
                vis[v] = 1;
                q.push(v);
                cnt[v]++;
                if (cnt[v] > n + 1) return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    n = read(), m = read();
    f(i, 1, m){
        int u, v, w;
        u = read(), v = read(), w = read();
        addedge(v, u, w);
    }
    f(i, 1, n) addedge(0, i, 0); 
    if (!spfa())
        f(i, 1, n) printf("%d ", dis[i]);
    else printf("%s", "NO");
    return 0;
}