#include <bits/stdc++.h>
using namespace std;
#define MAXN 5000010
int a[MAXN], d[MAXN];
int s[MAXN];
int n, p, l, r, z;
int ans = 0x7ffffff;
int main(){
    cin >> n >> p;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= p; ++i){
        cin >> l >> r >> z;
        d[l] += z;
        d[r + 1] -= z;
    }
    for (int i = 1; i <= n; ++i){
        s[i] = s[i - 1] + d[i];
        ans = (ans < s[i]) ? ans : s[i];
    }
    cout << ans << endl;
    return 0;
}