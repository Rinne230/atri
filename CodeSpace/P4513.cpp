#include <bits/stdc++.h>
using namespace std;
#define maxn 500001
typedef long long ll;
struct Node {ll lv, rv, val, sum;}t[maxn << 1];
ll a[maxn];
int ls(int x) {return x << 1;}
int rs(int x) {return x << 1 | 1;}
bool inRange(int L, int R, int l, int r){return (l <= L) && (R <= r);}//判断[L,R]是否被[l,r]包含
bool outofRange(int L, int R, int l, int r){return (L > r) || (R < l);}//判断[L,R]是否与[l,r]完全无交集
void pushup(int u){
    int lu = ls(u), ru = rs(u);
    t[u].sum = t[lu].sum + t[ru].sum;
    t[u].val = max({t[lu].val, t[ru].val, t[lu].rv + t[ru].lv});
    t[u].lv = max(t[lu].lv, t[lu].sum + t[ru].lv);
    t[u].rv = max(t[ru].rv, t[ru].sum + t[lu].rv);
}
void build(int u, int L, int R){
    if (L == R){
        t[u].lv = t[u].rv = t[u].val = t[u].sum = a[L];
        return;
    }
    int M = (L + R) >> 1;
    build(ls(u), L, M);
    build(rs(u), M + 1, R);
    pushup(u);
}
void update(int u, int L, int R, int p, ll s){
    if (L == R){
        t[u].sum = t[u].lv = t[u].rv = t[u].val = s;
        return;
    }
    int M = (L + R) >> 1;
    if (p <= M) update(ls(u), L, M, p, s);
    else update(rs(u), M + 1, R, p, s);
    pushup(u);
}
int query(int u, int L, int R, int l, int r){
    if(inRange(L, R, l, r)) return t[u].val;
    else if (!outofRange(L, R, l, r)){
        int M = (L + R) >> 1;
        return max(query(ls(u), L, M, l, r), query(rs(u), L, M, l, r));
    }else return 0;
}
int main(){
    int n, m;
    int op, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){cin >> a[i];}
    build(1, 1, n);
    while (m--){
        cin >> op >> x >> y;
        if (op == 1){
            if (x > y) swap(x, y);
            cout << query(1, 1, n, x, y) << endl;;
        }else{
            update(1, 1, n, x, y);
        }
    }
    return 0;
}
