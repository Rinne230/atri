#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100010
int n, m;
int p[maxn], a[maxn], b[maxn], c[maxn];
ll s[maxn], len[maxn], sum;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> p[i];
    }
    for (int i = 1; i <= n - 1; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= m - 1; i++){
        int x = min(p[i], p[i + 1]), y = max(p[i], p[i + 1]);
        s[x]++; s[y]--;
    }
    len[0] = 0;
    for (int i = 1; i <= n - 1; ++i){
        len[i] = len[i - 1] + s[i];
        //cout << len[i] << " ";
    }
    for (int i = 1; i <= n - 1; ++i){
        sum += (a[i] * len[i] > b[i] * len[i] + c[i]) ? b[i] * len[i] + c[i] : a[i] * len[i];
    }
    cout << sum << endl;
    return 0;
}