#include <bits/stdc++.h>
using namespace std;
#define maxn 5001
bool a[maxn], f[maxn];
int n, ans = 0x7ffffff, len;
int main(){
    cin >> n;
    char let;
    for (int i = 1; i <= n; ++i){
        cin >> let;
        a[i] = (let == 'F') ? 1 : 0;
    }
    for (int k = 1; k <= n; ++k){
        int sum = 0, tag = 0, flag = 0; 
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i){
            if ((a[i] + tag) % 2 == 0){
                if (i + k - 1 > n){
                    flag = 1;
                    break;
                }
                sum++;
                tag++;
                f[i + k - 1] = 1;
            }
            if (f[i] == 1){
                tag--;
                f[i] = 0;
            }
        }
        if (flag) continue;
        if (sum < ans){
            ans = sum;
            len = k;
        }
    }
    cout << len << " " << ans;
    return 0; 
}