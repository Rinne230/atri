#include <bits/stdc++.h>
using namespace std;
#define MAXN 500001
typedef long long ll;
ll a[MAXN], s[MAXN], q[MAXN], ans = -0x7ffffff, ans0 = -0x7ffffff;
int n, m;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        ans0 = max(ans0, a[i]);
    }
    int head = 1, tail = 1;
    for (int i = 1; i <= n; ++i){
        while (head < tail && s[q[tail - 1]] >= s[i]) tail--;
        //保证在队列元素不超量的情况下，队首的元素是最小的，为了s[i] - s[q[head]]max
        //详见P1886
        q[tail++] = i;
        while(q[head] < i - m) head++;
        ans = max(ans, s[i] - s[q[head]]);
    }
    cout << max(ans, ans0);
    return 0;
}