#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
typedef long long ll;
ll n, sumUni, maxUni, w[maxn], tmp1, tmp2;
pair<int, int> maxNum;
const int mod = 10007;
inline int read(){
    char ch = getchar(); int x = 0, f = 1;
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
vector<int> G[maxn << 1];
void addedge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
void init(){
    maxNum.first = 0, maxNum.second = 0;
    tmp1 = 0; tmp2 = 0;
}
int main(){
    n = read();
    for (int i = 1, u, v; i < n; ++i){
        u = read(), v = read();
        addedge(u, v);
    }
    for (int i = 1; i <= n; ++i){w[i] = read();}
    for (int i = 1; i <= n; ++i){
        init();
        for (int j = 0, v; j < G[i].size(); ++j){
            v = G[i][j];
            if (w[v] > maxNum.first){
                maxNum.second = maxNum.first;
                maxNum.first = w[v];
            }else if (w[v] > maxNum.second) maxNum.second = w[v];
            tmp1 = (tmp1 + w[v]) % mod;
            tmp2 = (tmp2 + w[v] * w[v]) % mod;
        }
        tmp1 = tmp1 * tmp1 % mod;
        sumUni = (sumUni + tmp1 - tmp2 + mod) % mod;
        maxUni = maxUni > maxNum.first * maxNum.second ? maxUni : maxNum.first * maxNum.second;
    }
    cout << maxUni << " " << sumUni << endl;
    return 0;
}