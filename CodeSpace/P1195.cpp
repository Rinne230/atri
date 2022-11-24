#include <bits/stdc++.h>
#define maxn 10007
using namespace std;
int fa[maxn], n, m, k, ans, cnt;
struct node {
    int u, v, w;
    friend bool operator < (node a, node b){return a.w < b.w;}
}e[maxn];
int find(int x){
    if (x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; ++i){
        int u = find(e[i].u), v = find(e[i].v);
        if (u != v) {
            fa[v] = u;
            ans += e[i].w;
            cnt++;
        }
        if (cnt == n - k) break;
    }
    if (cnt == n - k) printf("%d", ans);
    else puts("No Answer");
    return 0;
}