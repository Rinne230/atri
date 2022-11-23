#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
int n, m;
int a[maxn], c[maxn];
inline int lowbit(int x){return x & (-x);}
void add(int x, int y){
    for(int i = x; i <= n; i += lowbit(i)) c[i] += y;
}
int sum(int x){
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret += c[i];
    return ret;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        c[i] = a[i] - a[i - lowbit(i)];
    }
    while (m--){
        int op, x, y, k;
        cin >> op;
        if (op == 1){
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        }else{
            cin >> x;
            cout << sum(x) << endl;
        }
    }
    return 0;
}