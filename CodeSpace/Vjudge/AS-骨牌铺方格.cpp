#include <cstring>
#include <iostream>
#define maxn 64
using namespace std;
typedef long long ll;
ll n, f[64];
int main(){
    f[0] = f[1] = 1;
    for (int i = 2; i <= 64; ++i){
        f[i] = f[i - 1] + f[i - 2];
    }
    while (cin >> n){
        cout << f[n] << endl;
    }
    return 0;
}