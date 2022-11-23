#include <bits/stdc++.h>
#define maxn 250000
using namespace std;
struct edge{
    int u, v, w;
}e[maxn];
int fa[10005], B, A, ans, cnt;
bool cmp(edge a, edge b) {return a.w < b.w;}
int find(int x){
    if (x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}
void kruskal(){
    sort(e + 1, e + cnt + 1, cmp);
    for (int i = 1; i <= cnt; ++i){
        int u = find(e[i].u), v = find(e[i].v);
        if (u == v) continue;
        ans += e[i].w;
        fa[v] = u;
    }
}
int main(){
    scanf("%d%d", &A, &B);
    for (int i =  1; i <= B; ++i){
        fa[i] = i;
        e[++cnt].v = i;
        e[cnt].w = A;
    }
    for (int i = 1; i <= B; ++i){
        for (int j = 1; j <= B; ++j){
            int w; scanf("%d", &w);
            if (w){
                e[++cnt].u = i; e[cnt].v = j; e[cnt].w = w;
            }
        }
    }
    kruskal();
    printf("%d", ans);
}
