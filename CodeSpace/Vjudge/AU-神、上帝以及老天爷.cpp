#include <cstdlib>
#include<iostream>
#include<iomanip>
#define maxn 21
using namespace std;
typedef long long ll;
ll fac[maxn], f[maxn];
int n, m;
double ans; 
void init(){
    fac[0] = fac[1] = 1; f[2] = 1;
    for (int i = 2; i <= maxn; ++i) fac[i] = fac[i - 1] * i;
    for (int i = 3; i <= maxn; ++i) f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
}
int main(){
    init();
    cin >> n;
    while (n--){
        cin >> m;
        ans = (double) f[m] / fac[m];
        cout << fixed << setprecision(2) << 100.0 * ans << "%" << endl;
    }
    return 0;
}