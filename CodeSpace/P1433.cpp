#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0;
double x[16], y[16], dis[16][16];
double ans;
bool vis[16];
void dfs(int deep, int now, double sum){
    cnt++;
    if (cnt > 10000000) {
        cout << fixed << setprecision(2) << ans; 
        exit(0);
    }
    if (deep > n){
        ans = min(sum, ans);
    }
    for (int i = 1; i <= n; ++i){
        if (!vis[i]){
            double tmp = sum + dis[now][i];
            if (tmp > ans) continue;//剪枝
            vis[i] = 1;
            dfs(deep + 1, i, tmp);
            vis[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    ans = 1e6;
    for (int i = 1; i <= n; ++i){
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            dis[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    dfs(1, 0, 0);
    cout << fixed << setprecision(2) << ans; 
    return 0;
}