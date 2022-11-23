﻿//
//  main.cpp
//  P3834可持续化线段树
//
//  Created by 2307767173 on 2022/10/25.
//

#include <iostream>
#include <algorithm>
#include <map>
#define maxn 100005
using namespace std;
struct seg {
    int v, ls, rs;
}t[maxn << 8];
int rt[maxn << 2], cnt;
int lsh[maxn << 2], tot, n, m, node[maxn << 2];
void pushup(int o) { t[o].v = t[t[o].ls].v + t[t[o].rs].v; }
void change(int lsto, int& o, int l, int r, int q, int v) {
    if (!o) o = ++cnt;
    if (l == r) {
        t[o].v += v; 
        return;
    }
    int mid = (l + r) >> 1;
    if (q <= mid) {
        t[o].rs = t[lsto].rs;
        t[o].ls = ++cnt;
        t[t[o].ls] = t[t[lsto].ls];
        change(t[lsto].ls, t[o].ls, l, mid, q, v);
    }
    else {
        t[o].ls = t[lsto].ls;
        t[o].rs = ++cnt;
        t[t[o].rs] = t[t[lsto].rs];
        change(t[lsto].rs, t[o].rs, mid + 1, r, q, v);
    }
    pushup(o);
}
int query(int o1, int o2, int l, int r, int q) {
    if (l == r) return l;
    int mid = (l + r) >> 1, tmp = t[t[o2].ls].v - t[t[o1].ls].v;
    if (tmp >= q) return query(t[o1].ls, t[o2].ls, l, mid, q);
    else return query(t[o1].rs, t[o2].rs, mid + 1, r, q - tmp);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i];
        lsh[i] = node[i];
    }
    sort(lsh + 1, lsh + n + 1);
    tot = unique(lsh + 1, lsh + n + 1) - lsh - 1;
    for (int i = 1; i <= n; ++i) {
        node[i] = lower_bound(lsh + 1, lsh + tot + 1, node[i]) - lsh;
        change(rt[i - 1], rt[i], 1, tot, node[i], 1);
    }
    for (int i = 1; i <= m; ++i) {
        int l, r, q;
        cin >> l >> r >> q;
        cout << lsh[query(rt[l - 1], rt[r], 1, tot, q)] << endl;
    }
    return 0;
}

