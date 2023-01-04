#include <iostream>
#define maxn 51
using namespace std;
typedef long long ll;
ll f[maxn], n;
int main(){
    f[1] = 3; f[2] = f[3] = 6;
    for (int i = 4; i <= maxn; ++i){
        f[i] = f[i - 1] + 2 * f[i - 2];
        //当n-2与1同色，则n-1只需与n-2不同色，n-1与1一定不同色，n只有一种选择，方法数加n-1时候的方法数
        //当n-2与1不同色，则n-1本是最后一个方格，需要与1同色，n可以有两种选择，而此时则是n-2的方案数*2
    }
    while(cin >> n){
        cout << f[n] << endl;
    }
}
