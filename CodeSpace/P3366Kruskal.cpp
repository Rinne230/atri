#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
struct edge{
    int u, v, w;
}e[maxn];
int fa[5005], n, m, ans, tot = 1;
bool cmp(edge a, edge b) {return a.w < b.w;}
int find(int x){
    if (x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}
void kruskal(){
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; ++i){
        int u = find(e[i].u), v = find(e[i].v);
        if (u == v) continue;
        ans += e[i].w;
        fa[v] = u;
        ++tot;
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    kruskal();
    if (tot == n) printf("%d", ans);
    else puts("orz");
}