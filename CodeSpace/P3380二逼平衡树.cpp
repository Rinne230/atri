#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define inf 0x7fffffff
inline int read()
{
    char c = getchar();
    int x = 0, s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1; c = getchar();}
    while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c -'0'; c = getchar();}
    return x*s;
}
struct seg{
    int v;
    int ls, rs;
}t[maxn << 7];
struct quest{
    int a, b, c, d;
}q[maxn];
int len = 0;
int rt[maxn], n, m, tot, tem[maxn], tmp[maxn], cnt, num;
int lsh[maxn << 1], a[maxn];
void change(int &o, int l ,int r, int p, int v){
    if (!o) o = ++tot;
    if (l == r){
        t[o].v += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (p > mid) change(t[o].ls, l, mid, p, v);
    else change(t[o].rs, mid + 1, r, p, v);
}
int lowbit(int x){return x & (-x);}
void pushup(int o){t[o].v = t[t[o].ls].v + t[t[o].rs].v;}
void add(int o, int v){for (int i = o; i <= n; i += lowbit(i)) change(rt[i], 1, len, a[o], v);}
int query_num(int l, int r, int k){
    if (l == r) return l;
    int mid = (l + r) >> 1, sum = 0;
    for (int i = 1; i <= cnt; ++i) sum += t[t[tem[i]].ls].v;
    for (int i = 1; i <= num; ++i) sum -= t[t[tmp[i]].ls].v;
    if (k <= sum){
        for (int i = 1; i <= cnt; ++i) tem[i] = t[tem[i]].ls;
        for (int i = 1; i <= num; ++i) tmp[i] = t[tmp[i]].ls;
        return query_num(l, mid, k);
    }else{
        for (int i = 1; i <= cnt; ++i) tem[i] = t[tem[i]].rs;
        for (int i = 1; i <= num; ++i) tmp[i] = t[tmp[i]].rs;
        return query_num(mid + 1, r, k - sum);
    }
}
int find_num(int l, int r, int k){
    cnt = num = 0;
    for (int i = r; i; i -= lowbit(i)){
        tem[++cnt] = rt[i];
    }
    for (int i = l - 1; i; i -= lowbit(i)){
        tmp[++num] = rt[i];
    }
    return query_num(1, len, k);
}
int query_rnk(int l, int r, int k){
    if (l == r) return 0;
    int mid = (l + r) >> 1, sum = 0;
    if (k <= mid){
        for (int i = 1; i <= cnt; ++i) tem[i] = t[tem[i]].ls;
        for (int i = 1; i <= num; ++i) tmp[i] = t[tmp[i]].ls;
        return query_rnk(l, mid, k);
    }else{
        for (int i = 1; i <= cnt; ++i) sum += t[t[tem[i]].ls].v, tem[i] = t[tem[i]].rs;
        for (int i = 1; i <= num; ++i) sum -= t[t[tmp[i]].ls].v, tmp[i] = t[tmp[i]].rs;
        return sum + query_rnk(mid + 1, r, k);
    }
}
int find_rnk(int l, int r, int k){
    cnt  = num = 0;
    for (int i = r; i; i -= lowbit(i)){
        tem[++cnt] = rt[i];
    }
    for (int i = l - 1; i; i -= lowbit(i)){
        tmp[++num] = rt[i];
    }
    return query_rnk(1, len, k) + 1;
}
int find_pri(int l, int r, int k){
    int rk = find_rnk(l, r, k) - 1;
    if (rk == 0) return 0;
    return find_num(l, r, rk);
}
int find_nxt(int l, int r, int k){
    if (k == len) return len + 1;
    int rk = find_rnk(l, r, k + 1);
    if (rk == r - l + 2) return len + 1;
    return find_num(l, r, rk);
}
int main(){
    n = read(), m = read();
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        lsh[++len] = a[i];
    }
    for (int i = 1; i <= m; ++i){
        q[i].a = read(), q[i].b = read(), q[i].c = read();
        if (q[i].a != 3) q[i].d = read();
        else lsh[++len] = q[i].c;
        if (q[i].a == 4 || q[i].a == 5) lsh[++len] = q[i].d;
    }
    sort(lsh + 1, lsh + len + 1);
    len = unique(lsh + 1, lsh + len + 1) - lsh - 1;
    for (int i = 1; i <= n; ++i){
        a[i] = lower_bound(lsh + 1, lsh + len + 1, a[i]) - lsh;
        add(i, 1);
    }
    lsh[0] = -inf;
    lsh[len + 1] = inf;
    for (int i = 1; i <= m; ++i){
        if (q[i].a == 3){
            add(q[i].b, -1);
            a[q[i].b] = lower_bound(lsh + 1, lsh + len + 1, q[i].c) - lsh;
            add(q[i].b, 1);
        }
        if (q[i].a == 1){
            q[i].d = lower_bound(lsh + 1, lsh + len + 1, q[i].d) - lsh;
            cout << find_rnk(q[i].b, q[i].c, q[i].d) << endl;
        }
        if (q[i].a == 2){
            cout << lsh[find_num(q[i].b, q[i].c, q[i].d)] << endl;
        }
        if (q[i].a == 4){
            q[i].d = lower_bound(lsh + 1, lsh + len + 1, q[i].d) - lsh;
            cout << lsh[find_pri(q[i].b, q[i].c, q[i].d)] << endl;
        }
        if (q[i].a == 5){
            q[i].d = lower_bound(lsh + 1, lsh + len + 1, q[i].d) - lsh;
            cout << lsh[find_nxt(q[i].b, q[i].c, q[i].d)] << endl;
        }
    }
    return 0;
}