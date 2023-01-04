#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], r[maxn], n;
stack<int> s;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
int main(){
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = n; i >= 1; --i){
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            if (s.empty()) r[i] = 0;
            else r[i] = s.top();
            s.push(i);
    }
    for (int i = 1; i <= n; ++i) printf("%d\n", r[i]);
    return 0;
}