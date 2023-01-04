#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
int main(){
    stack<int> s;
    int n, a[3000001], f[3000001], L[3000001];
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = n; i >= 1; --i){
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if(s.empty()) L[i] = 0;
        else L[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; ++i) printf("%d ", L[i]);
    return 0;
}