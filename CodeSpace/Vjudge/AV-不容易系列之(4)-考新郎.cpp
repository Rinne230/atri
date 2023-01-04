#include <iostream>
#define maxn 21
using namespace std;
typedef long long ll;
ll fac[maxn];
ll f[maxn];
void init(){
    f[2] = 1; fac[0] = fac[1] = 1;
    for (int i = 3; i <= maxn; ++i) f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    for (int i = 2; i <= maxn; ++i) fac[i] = i * fac[i - 1]; 
}
ll solve(int n, int m){
    return fac[n] / fac[m] / fac[n - m] * f[m];
} 
int main(){
    int cnt;
    int n, m;
    scanf("%d", &cnt);
    init();
    while(cnt--){
        scanf("%d%d", &n, &m);
        printf("%lld\n", solve(n, m));
    }
    return 0;
}