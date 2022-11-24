#include <bits/stdc++.h>
#define maxn 10001
#define maxm 20001
using namespace std;
struct node{
    int u, v, w;
}e[maxm];
int fa[maxn], n, m, s, t;
bool cmp(node a, node b){return a.w < b.w;}
void init(){for (int i = 1; i <= n; ++i) fa[i] = i;}
int find(int x){
    if (x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}
int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    init();
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; ++i){
        int u = find(e[i].u), v = find(e[i].v);
        if (u != v) fa[v] = u;
        if (find(s) == find(t)){
            printf("%d", e[i].w);
            return 0;
        }
    }
    return 0;
}