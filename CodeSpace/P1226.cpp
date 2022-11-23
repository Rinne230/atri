// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll b, p, k;
// ll power(ll y, ll x){
//     if (x == 0) return 1 % k;
//     ll s = pow(y, x / 2);
//     if (x % 2 == 0) return s * s % k;
//     return s * s % k * y % k;
// }
// int main(){
//     cin >> b >> p >> k;
//     cout << power(b % k, p);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b, p, k;
ll power(ll y, ll x){
    if (x == 0) return 1 % k;
    ll sum = 1;
    while(x){
        if (x & 1) sum = sum * y % k;
        y = y * y % k;
        x >>= 1;
    }
}
int main(){
    cin >> b >> p >> k;
    cout << power(b % k, p);
    return 0;
}