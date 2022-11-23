#include <bits/stdc++.h>
using namespace std;
bool a[30001][30001]; 
int colmax, colmin;
int rowmax, rowmin;
int rowans, colans;
int n, x, y, L, W;
int main(){
    cin >> L >> W;
    cin >> n;
    if (n == 0){
        cout << L * W;
        return 0;
    }
    memset(a, false, sizeof(a));
    for (int i = 1; i <= n; ++i){
        cin >> x >> y;
        a[x][y] = true;
    }
    int lmin, rmax;
    for (int i = 1; i <= L; ++i){
        rowmax = 0;
        rowmin = W + 1;
        for (int j = 1; j <= W; ++j){
            if (a[i][j]) {
                lmin = j;
                break;
            }
        }
        for (int j = W; j >= 1; --j){
            if (a[i][j]) {
                rmax = j;
                break;     
            }
        }
        rowmin = min(rowmin, lmin);
        rowmax = max(rowmax, rmax);
    }
    rowans = rowmax - rowmin + 1;
    for (int i = 1; i <= W; ++i){
        colmax = 0;
        colmin = L + 1;
        for (int j = 1; j <= L; ++j){
            if (a[j][i]) {
                lmin = j;
                break;
            }
        }
        for (int j = L; j >= 1; --j){
            if (a[j][i]) {
                rmax = j;
                break;     
            }
        }
        colmin = min(colmin, lmin);
        colmax = max(colmax, rmax);
    }
    colans = colmax - colmin + 1;
    cout << max((colmax + 1) * (rowmax - 1), (colmax - 1) * (rowmax + 1));
    return 0;
}//空间占用太大无法通过，明天进行优化，读取的同时直接处理