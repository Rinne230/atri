#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
ll ans, a[maxn], s[maxn], n;
ll stk(){
    ll cur = 0, sum = 0, top = 1;
    for (int i = 1; i <= n; ++i){
        while (top > 1 && a[s[top]] < a[i]){
            cur -= (s[top] - s[top - 1]) * a[s[top]];
            top--;
        }
        cur += (i - s[top]) * a[i];
        sum += cur;
        s[++top] = i;
    }
    return sum;
}
int main(){
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    ans += stk();
    for (int i = 1; i <= n; ++i) a[i] = (-1) * a[i];
    ans += stk();
    printf("%lld", ans);
    return 0;
}