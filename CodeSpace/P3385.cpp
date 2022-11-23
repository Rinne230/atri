#include <bits/stdc++.h>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
#define _f(i, a, b) for (int i = (a); i >= (b); --i)
#define ef(i, u) for (int i = head[(u)]; i; i = nxt[i])
#define maxn 2005
#define maxm 20005
#define inf 2147483647
using namespace std;
typedef long long ll;
int dis[maxn], vis[maxn], head[maxn], cnt[maxn], to[maxm], val[maxm], nxt[maxm];
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
void init(){
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
    memset(to, 0, sizeof(to));
    memset(val, 0, sizeof(val));
    memset(nxt, 0, sizeof(nxt));
    cnt0 = 0;
}
bool spfa(){
    queue<int> q;
    f(i, 1, n){
        dis[i] = inf;
        vis[i] = 0;
    }
    q.push(1);
    dis[1] = 0;
    vis[1] = 1;
    cnt[1]++;
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
                if (cnt[v] > n) return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    int T = read();
    f(i, 1, T){
        init();
        n = read(), m = read();
        f(j, 1, m){
            int u = read(), v = read(), w = read();
            addedge(u, v, w);
            if(w >= 0) addedge(v, u, w);
        }
        if (spfa()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}