#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int n, L, R, ans = 0xcf;
int a[MAXN], q[MAXN], f[MAXN];
int main(){
    int head = 0, tail = 0;
    int p = 0;
    memset(f, 0xcf, sizeof(f));
    ans = f[0];
    //cout << ans << endl;
    f[0] = 0;
    cin >> n;
    cin >> L >> R;
    for (int i = 0; i <= n; ++i){cin >> a[i];}
    for (int i = L; i <= n; ++i){
        while (head < tail && q[head] + R < i) head++;
        while (head < tail && f[q[tail - 1]] <= f[p]) tail--;
        q[tail++] = p;
        //cout << q[head] << endl;
        f[i] = f[q[head]] + a[i];
        p++;
    }
    for(int i = n - R + 1; i <= n; ++i){ans = ans > f[i] ? ans : f[i];}                   
    cout << ans;
    return 0;
}
