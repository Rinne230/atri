#include <algorithm>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 500010;
const int MAXM = 500010;
inline ll pow(int x) {return 1ll * x * x;}
struct Node{
    int head[MAXN], nxt[MAXM << 1], to[MAXM << 1], tot;
    void addedge(int u, int v){
        to[++tot] = v;
        nxt[tot] = head[u];
        head[u] = tot;
        to[++tot] = u;
        nxt[tot] = head[v];
        head[v] = tot;
    }
}G, T;
int dfn[MAXN], low[MAXN], st[MAXN], top, idx, cnt, n, m, t1, t2, sz[MAXN], sznow;
void tarjan(int u){
    sz[u] = -1; ++sznow;
    dfn[u] = low[u] = ++cnt;
    st[++top] = u;
    for (int i = G.head[u]; i; i = G.nxt[i]){
        int v = G.to[i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]){
                ++idx; int vv;
                do{
                    vv = st[top--];
                    T.addedge(vv, idx);
                    ++sz[idx];
                } while (vv != v);
                ++sz[idx];
                T.addedge(u, idx);
            }
        }else 
            low[u] = min(low[u], dfn[v]);
    }
}
ll ans;
int sz2[MAXN];
void dfs(int u, int fa){
    sz2[u] = u <= n;
    //只有圆点才能作为s和f
    //而c在原点方点都可以
    ll num = 0;
    for (int i = T.head[u]; i; i = T.nxt[i]){
        int v = T.to[i];
        if (v != fa){
            dfs(v, u);
            num += 1ll * sz2[v] * sz2[u];
            sz2[u] += sz2[v];
        }
    }
    num += 1ll * sz2[u] * (sznow - sz[u]);
    num <<= 1;
    ans += 1ll * sz[u] * num;
}
int main(){
    scanf("%d%d", &n, &m);
    idx = n;
    for (int i = 1, u, v; i <= m; ++i){
        scanf("%d%d", &u, &v);
        G.addedge(u, v);
    }
    for (int i = 1; i <= m; ++i){
        if (!dfn[i]){
            sznow = 0;
            top = 0;
            tarjan(i);
            dfs(i, 0);  
        }
    }
    printf("%lld", ans);
    return 0;
}