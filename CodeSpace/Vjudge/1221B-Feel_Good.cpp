#include <iostream>
#include <stack>
#define maxn 1000010
using namespace std;
typedef long long ll;
ll n, a[maxn], sum[maxn], Lmin[maxn], Rmin[maxn], l = 1, r = 1, mx = 0;
stack<int> s;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i){
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(s.empty()) Lmin[i] = 0;
        else Lmin[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 1; --i){
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty()) Rmin[i] = n + 1;
        else Rmin[i] = s.top();
        s.push(i);
    }
    for(int i = 1; i <= n; ++i){
        ll ans;
        ans = sum[Rmin[i] - 1] - sum[Lmin[i]];
        ans *= a[i];
        if (ans > mx){
            l = Lmin[i] + 1;
            r = Rmin[i] - 1;
            mx = ans;
        }
    }
    printf("%lld\n",mx);
	printf("%lld %lld\n", l, r);
    return 0;
}