#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 101
ll n, k, s;
ll mid, ans;
ll fac[20], a[1005];
unordered_map<ll, int> Map[31];
void dfs1(ll x, ll num, ll sum){
    if (x > mid){
        Map[num][sum]++;
        return;
    }
    dfs1(x + 1, num, sum);
    if (sum + a[x] <= s) dfs1(x + 1, num, sum + a[x]);
    if (num < k && a[x] <= 19 && sum + fac[x] <= s) dfs1(x + 1, num + 1, sum + fac[a[x]]);
}
void dfs2(ll x, ll num, ll sum){
    if (x > n){
        for (int i = 0; i <= k - num; ++i) 
            if (Map[i][s - sum])
                ans += Map[i][s - sum];
        return;
    }
    dfs2(x + 1, num, sum);
    if (sum + a[x] <= s) dfs2(x + 1, num, sum + a[x]);
    if (num < k && a[x] <= 19 && sum + fac[a[x]] <= s) dfs2(x + 1, num + 1, sum + fac[a[x]]);
}
int main(){
    fac[1] = 1;
    for (int i = 2; i <= 19; ++i) fac[i] = fac[i - 1] * i;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    mid = n >> 1;
    dfs1(1, 0, 0);
    dfs2(mid + 1, 0, 0);
    cout << ans;
    return 0;
}