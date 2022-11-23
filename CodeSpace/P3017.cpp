#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
int a[501][501];
lli s[501][501];
int R, C, A, B, ans;
bool check(int mid){
    int now = 0, suma = 0;
    for (int i = 1; i <= R; ++i){
        int dis = 0, sumb = 0;
        for (int j = 1; j <= C; ++j){
            if (dis + (s[i][j] - s[i][j - 1]) - (s[now][j] - s[now][j - 1]) < mid)
                dis += (s[i][j] - s[i][j - 1]) - (s[now][j] - s[now][j - 1]);
                //如果加上这一列，还是不满足要求最小值最大的取值的情况，继续往后加
            else{
                //横向蛋糕切的数量加一，相当于切下来一块
                sumb++;
                dis = 0;
            }    
        }
        if (sumb >= B){
            //如果该此纵向切的蛋糕数满足要求的蛋糕数，则考虑纵向蛋糕数量
            now = i;
            suma++;
        }
    }
    //如果怎么切也切不够，返回false
    if (suma < A) return 0; 
    //反之，返回true
    return 1;
}
int main(){
    cin >> R >> C >> A >> B;
    for (int i = 1; i <= R; ++i){
        for (int j = 1; j <= C; ++j){
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    int l = 0, r = s[R][C];
    while(l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}