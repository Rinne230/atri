#include <bits/stdc++.h>
using namespace std;
#define maxn 500005
int n, m;
int c[maxn], a[maxn], pre[maxn];
inline int lowbit(int x) {return x & (-x);}
void add(int x, int k){//a[x] + k
    for (int i = x; i <= n; i += lowbit(i)) c[i] += k;
}
int sum(int x){//a[1] + a[2] + ...... + a[x]
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret += c[i];
    return ret;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        c[i] = pre[i] - pre[i - lowbit(i)];
    }
    while(m--){
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) add(x, y);
        else cout << sum(y) - sum(x - 1) << endl;
    }
    return 0;
}