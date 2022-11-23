#include <bits/stdc++.h>
using namespace std;
#define MAXN 50001
#define MAXQ 180001
int f1[22][MAXN], f2[22][MAXN];
int n, q;
int query(int l, int r){
    int a, b;
    int len = log2(r - l + 1);
    a = max(f1[len][l], f1[len][r - (1 << len) + 1]);
    b = min(f2[len][l], f2[len][r - (1 << len) + 1]);
    int ans = a - b;
    //cout << ans << endl;
    return ans;
}
int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> f1[0][i];
        f2[0][i] = f1[0][i];
    }
    for (int i = 1; i <= 20; ++i){
        for (int k = 1; k + (1 << i) <= n + 1; ++k){
            f1[i][k] = max(f1[i - 1][k], f1[i - 1][k + (1 << (i - 1))]);
            f2[i][k] = min(f2[i - 1][k], f2[i - 1][k + (1 << (i - 1))]);
        }
    }
    int l, r;
    for (int i = 1; i <= q; ++i){
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}