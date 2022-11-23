#include <bits/stdc++.h>
using namespace std;
#define maxn 500010
typedef long long ll;
ll a[maxn], s[maxn];
int main(){
    int n, m, l, r;
    cin >> n;
    for (int i = 1; i <= n; ++i){cin >> a[i];}
    for (int i = 1; i <= n; ++i){s[i] = s[i - 1] + a[i];}
    cin >> m;
    for (int i = 1; i <= m; ++i){
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;;
    }
    return 0;
}