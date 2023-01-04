#include <iostream>
using namespace std;
typedef long long ll;
ll p(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = (res * a) % 1000;
        a = (a * a) % 1000;
        b >>= 1;
    }
    return res;
}
int main(){
    ll a, b;
    while (cin >> a >> b){
        if (!a && !b) break;
        cout << (p(a, b) % 1000) << endl;
    }
    return 0;
}