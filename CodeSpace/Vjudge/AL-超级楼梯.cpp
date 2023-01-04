#include <iostream>
#define maxn 51
using namespace std;
typedef long long ll;
ll n, m, f[maxn];
int main(){
    f[1] = 1; f[2] = 1;
    for (int i = 3; i <= maxn - 1; ++i){
        f[i] = f[i - 1] + f[i - 2];
    }
    cin >> n;
    while (n--){
        cin >> m;
        cout << f[m] << endl;
    }
}