#include <stack>
#include <iostream>
#include <algorithm>
#define maxn 1000010
using namespace std;
typedef long long ll;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
struct cow{
    int idx, h;
};
stack<cow> s;
int h[maxn], l[maxn], r[maxn], ans = 0;
int main(){
    int n = read();
    for (int i = 1; i <= n; ++i) h[i] = read();
    for (int i = 1; i <= n; ++i){
        while (!s.empty() && s.top().h < h[i]) s.pop();
        if (s.empty()) l[i] = 0;
        else l[i] = s.top().idx;
        s.push(cow{i, h[i]}); 
    }
    while(!s.empty()) s.pop();
    for (int i = n; i >= 1; --i){
        while (!s.empty() && s.top().h > h[i]) s.pop();
        if (s.empty()) r[i] = n + 1;
        else r[i] = s.top().idx;
        s.push(cow{i, h[i]});
    }
    for (int i = n; i >= 1; --i){
        for (int j = l[i] + 1; j < i; ++j){
            if (r[j] > i){
                ans = max(ans, i - j + 1);
                break;
            }
        }
        if (ans >= i) break;
    }
    cout << ans << endl;
    return 0;
}