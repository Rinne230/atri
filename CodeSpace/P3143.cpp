#include <bits/stdc++.h>
using namespace std;
long long n, m, r = 2;
long long maxNum = 0, ans = 0;
long long a[100001];
long long b[100001];
int main(){
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i){
        cin >> a[i];
    }
    a[n + 1] = 2100000000;
    sort(a + 1, a + n + 1);
    for (long long i = 1; i <= n; ++i){
        while(a[r] <= a[i] + m) r++;
        b[r] = max(r - i, b[r]);//维护区间最大长度
        maxNum = max(maxNum, b[i]);//区间前的部分最大长度
        ans = max(ans, maxNum + r - i);//[l, r)所以r - l不用加1
    }
    cout << ans << endl;
    return 0;
}