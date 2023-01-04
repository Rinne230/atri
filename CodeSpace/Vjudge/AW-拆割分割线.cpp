#include <bits/stdc++.h>
#define maxn 10001
using namespace std;
int f[maxn];
int find(int n){
    if (f[n]) return f[n];
    if (n == 1) return f[1] = 2;
    return f[n] = find(n - 1) + 4 * (n - 1) + 1;
}
int main(){
    int n, m;
    cin >> n;
    while (n--){
        scanf("%d", &m);
        printf("%d\n", find(m));
    }
    return 0;
}