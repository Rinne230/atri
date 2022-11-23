#include <bits/stdc++.h>
#define maxn 2000002
#define mod 100003
#define inf 0x7fffffff
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
#define ef(i, u) for (int i = head[(u)]; i; i = nxt[i])
using namespace std;
int to[maxn], head[maxn], nxt[maxn], vis[maxn >> 1], cnt[maxn >> 1], d[maxn >> 1];
int cnt0, n, m;
queue<int> q;
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return f * x;
}
void addedge(int u, int v){
    to[++cnt0] = v;
    nxt[cnt0] = head[u];
    head[u] = cnt0;
}
int main(){
    n = read(), m = read();
    f(i, 1, m){
        int u = read(), v = read();
        addedge(u, v);
        addedge(v, u);
    }
    d[1] = 0;
    vis[1] = 1;
    cnt[1] = 1;
    q.push(1);          
    while(!q.empty()){
        int u = q.front(); q.pop();
        ef(i, u){
            int v = to[i];
            if (!vis[v]){
                vis[v] = 1;
                d[v] = d[u] + 1;
                q.push(v);
            }
            if (d[v] == d[u] + 1) cnt[v] = (cnt[v] + cnt[u]) % mod;
        }
    }
    f(i, 1, n) printf("%d\n", cnt[i]);
    return 0;
}