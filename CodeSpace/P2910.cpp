#include <bits/stdc++.h>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
#define maxn 105
#define maxm 10005
using namespace std;
typedef long long ll;
int n, m, a[maxm], dis[maxn][maxn];
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
int main(){
    n = read(), m = read();
    f(i, 1, m) a[i] = read();
    f(i, 1, n) 
        f(j, 1, n) dis[i][j] = read();
    f(k, 1, n)
        f(i, 1, n)
            f(j, 1, n) dis[i][j] = min((ll)dis[i][j], (ll)dis[i][k] + dis[k][j]);
    int ans = 0;
    f(i, 1, m - 1) ans += dis[a[i]][a[i + 1]];
    printf("%d", ans);
    return 0;
}