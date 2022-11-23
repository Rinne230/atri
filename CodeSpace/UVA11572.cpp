#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 100010
typedef long long ll;
int a[MAXN], cnt[MAXN];
int t, n, ans, l, r, tmp, num;
int main(){
    cin >> t;
    while (t--){
        cin >> n;
        ans = -0x7ffffff;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
            if (cnt[a[i]] == 1) num++;
        }
        //cout << num << endl;
        l = 1, r = 1, tmp = 0;
        memset(cnt, 0, sizeof(cnt));
        while (l <= r && r <= n){
            if (tmp < num){
                r++;
                //cout << 'r' << r << endl;
                cnt[a[r - 1]]++;
                if (cnt[a[r - 1]] == 1) tmp++; 
            }else{
                if (tmp == num) ans = (r - l > ans) ? r - l: ans;
                cnt[a[l]]--;
                if (cnt[a[l]] == 0) tmp--;
                l++;
                //cout << 'l' << l << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}