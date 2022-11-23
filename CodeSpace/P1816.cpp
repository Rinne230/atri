#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
int f1[21][maxn], f2[21][maxn], m, n;
int query(int l, int r){
    int b;
    int len = log2(r - l + 1);
    b = min(f2[len][l], f2[len][r - (1 << len) + 1]);
    return b;
}
int main(){
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        cin >> f1[0][i];
        f2[0][i] = f1[0][i];
    }
    for (int i = 1; i <= 20; ++i){
        for (int j = 1; j + (1 << i) <= m + 1; ++j){
            f2[i][j] = min(f2[i - 1][j], f2[i - 1][j + (1 << i - 1)]);
        }
    }   
    for (int i = 1; i <= n; ++i){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << " ";
    }
    return 0;
}