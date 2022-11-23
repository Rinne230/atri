// #include <iostream>
// using namespace std;
// int main(){
//     int n, a, f = 0, ans = -100001;
//     cin >> n;
//     for (int i = 1; i <= n; ++i){
//         cin >> a;
//         f = max(f + a, a);
//         ans = max(f, ans);
//     }
//     cout << ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
#define INF 0x7ffffff
int n, a[MAXN], ans = -INF;
void dfs(int l, int r){
    int mid = (l + r) >> 1;
    if (l == r) ans = max(ans, a[l]);
    else{
        dfs(l, mid), dfs(mid + 1, r);
    }
    int pre = -INF, suf = -INF;
    for (int i = mid, tmp = 0; i >= l; --i){
        tmp += a[i];
        pre = max(tmp, pre);
    }
    for (int i = mid + 1, tmp = 0; i <= r; ++i){
        tmp +=a[i];
        suf = max(suf, tmp);
    }
    ans = max(suf + pre, ans);
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1, n);
    cout << ans << endl;
    return 0;
}
