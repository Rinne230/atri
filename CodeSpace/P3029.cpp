#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 500100
struct node{
    ll x;
    ll y;
    ll id;
}a[maxn];
ll b[maxn], c[maxn], cnt[maxn], btop, ctop, n, num, sum, ans = 2e9;
map<ll, ll> Map;
bool cmp(node p, node q) {return p.x < q.x;}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y;
        b[++btop] = a[i].y;
    }
    sort(b + 1, b + btop + 1);
    for (int i = 1; i <= btop; ++i){
        if(b[i] != b[i - 1]){
            c[++ctop] = b[i];
            Map[b[i]] = ctop;
        }
    }
    for (int i = 1; i <= n; ++i){
        a[i].id = Map[a[i].y];
        if (!cnt[a[i].id]) {
            sum++;
            cnt[a[i].id]++;
        }
    }
    sort(a + 1, a + n + 1, cmp);
    int l = 1, r = 1;
    num = 0;
    memset(cnt, 0, sizeof(cnt));
    while (l <= r && r <= n + 1){
        if (num < sum){
            r++;
            cnt[a[r - 1].id]++;
            if (cnt[a[r - 1].id] == 1) num++; 
        }else{
            if (num == sum){
                ans = min(a[r - 1].x - a[l].x, ans);
            }
            cnt[a[l].id]--;
            if (cnt[a[l].id] == 0) num--;
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}
