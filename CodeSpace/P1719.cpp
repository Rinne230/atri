#include <bits/stdc++.h>
using namespace std;
int a[121][121];
int s[121][121];
int n;
int qsum(int x1, int y1, int x2, int y2){
    return s[x2][y2] + s[x1 - 1][y1 - 1] - s[x2][y1 - 1] - s[x1 - 1][y2];
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
        }
    int ans = -0x7ffffff;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            for (int k = i; k <= n; ++k){
                for (int l = j; l <= n; ++l){
                    ans = max(ans, (qsum(i, j, k, l)));
                }
            }
        }
    }
    cout << ans;
    return 0;
}