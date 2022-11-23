#include<bits/stdc++.h>
using namespace std;
struct Node{
    int id, l, r;
}a[400005];
int n, m, cnt[400005];
int f[21][400005];
bool cmp(Node x, Node y){return x.l < y.l;}
void init(){
    for(int i = 1, p = i; i <= 2 * n; ++i){
        while (p <= 2 * n && a[p].l <= a[i].r) p++;
        int pos = p - 1;
        f[0][i] = pos;
    }
    for (int i = 1; i < 20; ++i){
        for (int j = 1; j <= 2 * n; ++j){
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
}
void search(int k){
    int lmt = a[k].l + m, ans = 1, p = k;
    for (int i = 19; i >= 0; i--){
        if (f[i][k] && a[f[i][k]].r < lmt){
            ans += (1 << i);
            k = f[i][k];
        }
    }
    cnt[a[p].id] = ans + 1;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].l >> a[i].r;
        a[i].r += (a[i].r < a[i].l) ? m : 0;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i){
        a[i + n] = a[i];
        a[i + n].l = a[i].l + m;
        a[i + n].r = a[i].r + m;
    }
    init();
    for (int i = 1; i <= n; ++i){
        search(i);
    }
    for (int i = 1; i <= n; ++i){
        cout << cnt[i] << " ";
    }
    return 0;
}