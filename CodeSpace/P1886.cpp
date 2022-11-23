#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000001], q[2000001], tail, head;
ll n, k;
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    tail = 0, head = 0;
    for (int i = 1; i <= n; ++i){
        while (head < tail && q[head] + k <= i) head++;
        while (head < tail && a[q[tail - 1]] > a[i]) tail--;
        q[tail++] = i;
        if (i >= k) cout << a[q[head]] << " ";
    }//储存最小值
    cout << endl;
    tail = 0, head = 0;
    memset(q, 0, sizeof(q));
    for (int i = 1; i <= n; ++i){
        while (head < tail && q[head] + k <= i) head++;
        while (head < tail && a[q[tail - 1]] < a[i]) tail--;
        q[tail++] = i;
        if (i >= k) cout << a[q[head]] << " ";
    }//储存最大值
    return 0;
}