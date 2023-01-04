#include <iostream>
#define maxn 51
using namespace std;
typedef long long ll;
ll ans[maxn];
int n, s, e;
void init(){
    ans[0] = ans[1] = 1; ans[2] = 2;
    for (int i = 3; i <= maxn; ++i){
        ans[i] = ans[i - 1] + ans[i - 2];
    }
}
int main(){
    init();
    cin >> n;
    while(n--){
        cin >> s >> e;
        cout << ans[e - s] << endl;
    }
    return 0;
}