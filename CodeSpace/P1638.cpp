#include <iostream>
using namespace std;
#define MAXN 1000010
int n, m, l, r, sum[2005], a[MAXN];
int ans, ansl, ansr, num;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    l = 1, r = 1, num = 0, ans = MAXN;
    while (l <= r && r <= n + 1){
        if (num < m){
            r++;
            sum[a[r - 1]]++;
            if (sum[a[r - 1]] == 1) num++;
        }
        else {
            if (ans > r - l){
                ans = r - l;
                ansl = l;
                ansr = r - 1;
            }
            sum[a[l]]--;
            if (sum[a[l]] == 0) num--;
            l++;
        }
    }
    cout << ansl << " " << ansr;
    return 0;
}