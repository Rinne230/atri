#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ull;
#define maxn 100
int n;
ll a[maxn], M[maxn], m[maxn], LCM = 1, ans;
inline int read(){
    char ch = getchar(); int x = 0, f = 1;
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
inline void write(int x)
 {
     char F[200];
     int tmp = x > 0 ? x:-x ;
     if(x < 0)putchar('-') ;
     int cnt = 0 ;
        while(tmp>0)
        {
            F[cnt++]=tmp%10+'0';
            tmp/=10;
        }
        while(cnt > 0) putchar(F[--cnt]) ;
 }
void exgcd(ll a, ll b, ll &x, ll &y){
    if (!b){x = 1, y = 0; return;}
    exgcd(b, a % b, y, x);
    y -= a/b * x;
}

int main(){
    n = read();
    for (int i = 1; i <= n; ++i){
        m[i] = read();
        LCM *= m[i];
        a[i] = read();
    }
    for (int i = 1; i <= n; ++i){
        M[i] = LCM / m[i];
        ll x = 0, y = 0;
        exgcd(M[i], m[i], x, y);
        ans += a[i] * M[i] * (x < 0 ? x + m[i] : x);
    }
    printf("%d\n", ans % LCM);
    return 0;
}
