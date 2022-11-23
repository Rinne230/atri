#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100010
ll a[maxn], d;
ll n, upw, dow, ans1, ans2;
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i){
        d = a[i + 1] - a[i];
        if (d > 0) upw += d;
        else dow -= d;
    }
    ans1 = max(upw, dow);
    ans2 = abs(upw - dow) + 1;//一加一减，两个操作会相互抵消
    cout << ans1 << endl << ans2;
    return 0;
}