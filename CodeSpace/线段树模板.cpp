#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 400010
ll a[maxn], w[maxn * 4], lazyTag[maxn * 4];
void pushup(int u){w[u] = w[u << 1] + w[u << 1 | 1];}//上推
void makeTag(int u, int len, ll x){//下放lazytag
    lazyTag[u] += x;
    w[u] += len * x;
}
void pushdown(int u, int L, int R){//下放lazytag的索引
    int M = (L + R) >> 1;
    makeTag(u << 1, M - L + 1, lazyTag[u]);
    makeTag(u << 1 | 1, R - M, lazyTag[u]);
    lazyTag[u] = 0;
}
void build(int u, int L, int R){//递归建树
    if (L == R) {
        w[u] = a[L];
        return;
    }
    int M = (L + R) >> 1;
    build(u << 1, L, M);
    build(u << 1 | 1, M + 1, R);
    pushup(u);
}
bool inRange(int L, int R, int l, int r){return (l <= L) && (R <= r);}//判断[L,R]是否被[l,r]包含
bool outofRange(int L, int R, int l, int r){return (L > r) || (R < l);}//判断[L,R]是否与[l,r]完全无交集
ll query(int u, int L, int R, int l, int r){//区间查询
    if (inRange(L, R, l, r)) return w[u];
    else if (!outofRange(L, R, l, r)){
        int M = (L + R) >> 1;
        pushdown(u, L, R);
        return query(u << 1, L, M, l, r) + query(u << 1 | 1, M + 1, R, l, r);
    }else return 0;
}
void update(int u, int L, int R, int l, int r, ll x){//区间修改
    if (inRange(L, R, l, r)) makeTag(u, R - L + 1, x);
    else if (!outofRange(L, R, l, r)){
        int M = (L + R) >> 1;
        pushdown(u, L, R);
        update(u << 1, L, M, l, r, x);
        update(u << 1 | 1, M + 1, R, l, r, x);
        pushup(u);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){cin >> a[i];}
    build(1, 1, n);
    for (int i = 1; i <= m; ++i){
        int op, x, y;
        ll k;
        cin >> op;
        if (op == 1){
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }else {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}