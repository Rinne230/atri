#include <bits/stdc++.h>
#define maxn 5001
#define maxm 15001
#define inf 0x3f3f3f3f
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
#define ef(i, u) for (int i = head[(u)]; i; i = nxt[i])
using namespace std;
typedef long long ll;
int head[maxn], to[maxm], vis[maxn], val[maxm], nxt[maxm], cnt[maxm], dis[maxn];
int n, m, opt, cnt0;
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
bool spfa(int x){
    queue<int> q;
    memset(dis, inf, sizeof(dis));
    q.push(x);
    dis[x] = 0;
    vis[x] = 1;
    cnt[x]++;
    while (!q.empty()){
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
                }
                if (cnt[v] > n) return 1;
            }
        }
    }
    return 0;
}
int main(){
    n = read(), m = read();
    f(i, 1, m){
        int u, v, w;
        opt = read();
        if (opt == 1){
            u = read(), v = read(), w = read();
            addedge(u, v, -w);
        }else if (opt == 2){
            u = read(), v = read(); w = read();
            addedge(v, u, w);
        }else{
            u = read(), v = read();
            addedge(u, v, 0);
            addedge(v, u, 0);
        }
    }
    f(i, 1, n) addedge(n + 1, i, 0);
    if (spfa(n + 1)){
        printf("No");
        return 0;
    }
    printf("Yes");
    return 0;
}