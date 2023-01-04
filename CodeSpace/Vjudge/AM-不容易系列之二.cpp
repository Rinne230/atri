#include <iostream>
#define maxn 51
typedef long long ll;
using namespace std;
ll f[maxn], n, m;
int main(){
    f[0] = 3;
    for (int i = 1; i < maxn; ++i){f[i] = ((f[i - 1] - 1) << 1);}
    cin >> n;
    while(n--){
        cin >> m;
        cout << f[m] << endl;
    }
}