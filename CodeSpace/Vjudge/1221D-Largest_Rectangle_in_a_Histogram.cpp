#include <bits/stdc++.h>
#include <cstddef>
#include <cstring>
#define maxn 1000010
using namespace std;
typedef long long ll;
int h[maxn], l[maxn], r[maxn], n;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
void init(){
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
}
int main(){
    while (cin >> n && n){
        init();
        for (int i = 1; i <= n; ++i) h[i] = read();
        stack<int> s;
        for (int i = 1; i <= n; ++i){
            while (!s.empty() && h[s.top()] >= h[i]) s.pop();
            if (s.empty()) l[i] = 1;
            else l[i] = s.top() + 1;
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n; i >= 1; --i){
            while (!s.empty() && h[s.top()] >= h[i]) s.pop();
            if (s.empty()) r[i] = n + 1;
            else r[i] = s.top();
            s.push(i);
        }
        ll ans = 0;
        for (int i = 1; i <= n;i++) ans = max(ans, 1ll * h[i] * (r[i] - l[i]));
        cout << ans << endl;
    }
    return 0;
}