#include <iostream>
#define maxn 41
using namespace std;
typedef long long ll;
ll f[maxn][2];//0表示填O，1表示不填O
int n, m;
int main(){
    f[1][0] = 1;
    f[1][1] = 2;
    for (int i = 2; i <= maxn; ++i){
        f[i][0] = f[i - 1][1]; f[i][1] = 2 * (f[i - 1][1] + f[i - 1][0]);
    }
    while (cin >> n){
        cout << f[n][0] + f[n][1] << endl;
    }
    return 0;
}