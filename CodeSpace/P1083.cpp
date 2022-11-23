#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 1000010
ll date[maxn];  
ll d[maxn], s[maxn], t[maxn], sum[maxn];
ll a[maxn], de[maxn];
int n, m;
void init(){
    memset(a, 0, sizeof(a));
    memset(de, 0, sizeof(de));
}
bool check(int mid){
    init();
    bool flag = true;
    for (int i = 1; i <= mid; ++i){
        de[s[i]] += d[i];
        de[t[i] + 1] -= d[i];
    }
    for (int i = 1; i <= n; ++i){
        a[i] = a[i - 1] + de[i];
    }
    for (int i = 1; i <= n; ++i){
        if(a[i] > sum[i]){
            flag = false;
            break;
        }
    }
    return flag;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> sum[i];
    for (int i = 1; i <= m; ++i){
        cin >> d[i] >> s[i] >> t[i];
        de[s[i]] += d[i];
        de[t[i] + 1] -= d[i];
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i){
        a[i] = a[i - 1] + de[i];
        if (a[i] > sum[i]) {
            flag = false;
            break;
        }
    }
    if (flag){
        cout << 0;
        return 0;
    }
    int l = 0, r = m, ans = 0;;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            l = mid + 1;
        }else{
            r = mid - 1;
            ans = mid;
        }
    }
    cout << -1 << endl << ans;
    return 0;
}