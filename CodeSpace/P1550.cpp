#include <bits/stdc++.h>
#include <queue>
#define maxn 100001
using namespace std;
int a[301][301], n, ans;
int fa[301];
struct node {
    int u, v, w;
    friend bool operator < (node a, node b){
        return a.w > b.w;
    }
}e[maxn];
priority_queue<node> q;
int find(int x){
    if (x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}
void kruskal(){
    while(!q.empty()){
        node p = q.top();
        q.pop();
        if (find(p.u) != find(p.v)) {
            fa[find(p.v)] = find(p.u);
            ans += p.w;
        }
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; ++i) fa[i] = i;
    for (int i = 1, w; i <= n; ++i){
        scanf("%d", &w);
        q.push((node){i, n + 1, w});
        q.push((node){n + 1, i, w});
    }   
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            scanf("%d", &a[i][j]);
            if (i == j) continue;
            q.push((node){i, j, a[i][j]});
        }
    }
    kruskal();
    printf("%d", ans);
}