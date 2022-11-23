#include <bits/stdc++.h>
using namespace std;
const int maxn = 66;
int n ,sum, mn = maxn, x, d;
int len[maxn], a[maxn], pre[maxn];
//len:当前长度为i的木棍还剩多少根
//pre表示长度小雨i的最长木棍长度
void dfs(int u, int k, int p){
    //当前长棍子还有u没有拼，还有k根长棍没拼，当前长棍用的最短短棍长度是p
    if (u == 0){
        dfs(d, k - 1, a[n]);
        return;
    }
    if (k == 0){
        cout << d;
        exit(0);
    }
    p = p < u ? p : u;
    while (p && len[p] == 0) --p;
    while (p){
        if (len[p]){
            --len[p];
              dfs(u - p, k, p);
            ++len[p];
            if ((u == p) || (u == d)) return;//最后一条剪枝叶
            p = pre[p];
        }else(p = pre[p]);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        sum += x;
        ++len[a[i] = x];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i){
        if (a[i] != a[i - 1])
            pre[a[i]] = a[i - 1];
    }
    for (int d = a[n]; (d << 1) <= sum; ++d){
        if (sum % d == 0){
            dfs(d, sum / d, a[n]);
        }
    }cout << sum;
    return 0;
}