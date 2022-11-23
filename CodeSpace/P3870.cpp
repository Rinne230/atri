#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 1000010
ll w[maxn * 4], tag[maxn * 4];
int ls(int x){return x << 1;}
int rs(int x){return x << 1 | 1;}
void pushup(int u){w[u] = w[ls(u)] + w[rs(u)];}
void makeTag(int u, int l ,int r){
    w[u] = r - l + 1 - w[u];
    tag[u] ^= 1;
}
void pushdown(int u, int L, int R){
    if (tag[u] == 0) return;
    int M = (L + R) >> 1;
    makeTag(ls(u), L, M);
    makeTag(rs(u), M + 1, R);
    tag[u] = 0;
}
bool inRange(int L, int R, int l, int r){return (l <= L) && (R <= r);}//判断[L,R]是否被[l,r]包含
bool outofRange(int L, int R, int l, int r){return (L > r) || (R < l);}//判断[L,R]是否与[l,r]完全无交集
ll query(int u, int L, int R, int l, int r){
    if (inRange(L, R, l, r)) return w[u]; 
    else if (!outofRange(L, R, l, r)){
        int M = (L + R) >> 1;
        pushdown (u, L, R);
        return query(ls(u), L, M, l, r) + query(rs(u), M + 1, R, l, r);
    }else return 0;
}
void update(int u, int L, int R, int l, int r){
    if (inRange(L, R, l, r)) makeTag(u, L, R);
    else if (!outofRange(L, R, l, r)){
        int M = (L + R) >> 1;
        pushdown(u, L, R);
        update(ls(u), L, M, l, r);
        update(rs(u), M + 1, R, l, r);
        pushup(u);
    }
}
int main(){
    int n, m, x, y;
    bool opt;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> opt >> x >> y;
        if (!opt) update(1, 1, n, x, y);
        else cout << query(1, 1, n, x, y) << endl;
    }
    return 0;
}