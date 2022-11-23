#include <bits/stdc++.h>
using namespace std;
#define maxn 2000
int n, x, y;
void dfs(int t, int sx, int sy, int x, int y){
    if (t == 0) return;
    int len = (1 << t - 1);
    if (x < sx + len && y < sy + len){
        cout << sx + len << " " << sy + len << " " << 1 << endl;
        dfs(t - 1, sx, sy, x, y);
        dfs(t - 1, sx, sy + len, sx + len - 1, sy + len);
        dfs(t - 1, sx + len, sy, sx + len, sy + len - 1);
        dfs(t - 1, sx + len, sy + len, sx + len, sy + len);
    }else if (x < sx + len){
        cout << sx + len << " " << sy + len - 1 << " " << 2 << endl;
        dfs(t - 1, sx, sy, sx + len - 1, sy + len - 1);
        dfs(t - 1, sx, sy + len, x, y);
        dfs(t - 1, sx + len, sy, sx + len, sy + len - 1);
        dfs(t - 1, sx + len, sy + len, sx + len, sy + len);
    }else if (y < sy + len){
        cout << sx + len - 1 << " " <<  sy + len << " " << 3 <<  endl;
        dfs(t - 1, sx, sy, sx + len - 1, sy + len - 1);
        dfs(t - 1, sx, sy + len, sx + len - 1, sy + len);
        dfs(t - 1, sx + len, sy, x, y);
        dfs(t - 1, sx + len, sy + len, sx + len, sy + len);
    }
    else {
        cout << sx + len - 1 << " " << sy + len - 1 << " " << 4 << endl;
        dfs(t - 1, sx, sy, sx + len - 1, sy + len - 1);
        dfs(t - 1, sx, sy + len, sx + len - 1, sy + len);
        dfs(t - 1, sx + len, sy, sx + len, sy + len - 1);
        dfs(t - 1, sx + len, sy + len, x, y);
    }
}
int main(){
    cin >> n >> x >> y;
    dfs(n, 1, 1, x, y);
    return 0;
}