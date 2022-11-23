#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
int n, q, d[maxn], c[maxn], f[21][maxn], g[21][maxn], rmax[21][maxn], log_2[maxn];
int query(int A, int B){
    int x = log_2[B - A + 1];
    return max(rmax[x][A], rmax[x][B - (1 << x) + 1]);
}
int main(){
    cin >> n >> q; 
    for (int i = 1; i <= n; ++i) {
        cin >> d[i] >> c[i];
        rmax[0][i] = d[i];
    }
    for (int i = 2; i <= n; ++i) log_2[i] = log_2[i >> 1] + 1;
    for (int i = 1; (1 << i) <= n; ++i){
        for (int k = 1; k <= n - (1 << i) + 1; ++k){
            rmax[i][k] = max(rmax[i - 1][k], rmax[i - 1][k + (1 << (i - 1))]);
        }
    }//倍增存区间半径极大值
    c[n + 1] = 0x7ffffff;
    for (int i = 1; i <= n; ++i){
        int l = i + 1, r = n + 1, mid;
        while(l < r){
            mid = l + r >> 1;
            if (query(i + 1, mid) <= d[i]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        f[0][i] = l;//f[0][i]存溢出区后下一个盘子
        g[0][i] = c[f[0][i]];//g[0][i]溢出到下一个盘子的容量和
    }
    f[0][n] = n + 1;;
    g[0][n] = c[f[0][n]];
    for (int i = 1; i <= 16; ++i){
        for (int j = 1; j <= n; ++j){
            f[i][j] = f[i - 1][f[i - 1][j]];
            g[i][j] = g[i - 1][j] + g[i - 1][f[i - 1][j]];
        }
    }
    while(q--){
        int r, v;
        cin >> r >> v;
        if (v > c[r]){
            v -= c[r];
            for (int t = 16; t >= 0; --t){
                if (v > g[t][r]){
                    v -= g[t][r];
                    r = f[t][r];
                }
            }
            r = f[0][r];
        }
        if (r == n + 1) r = 0;
        cout << r << endl;
    }
    return 0;
}