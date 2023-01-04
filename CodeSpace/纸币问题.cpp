#include<bits/stdc++.h>
#define maxn 0x7fffffff
using namespace std;
int f[10010], a[1010], n, w;
int main(){
    f[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &w);
    for (int i = 1; i <= w; ++i){
        f[i] = maxn;
        for (int j = 1; j <= n; ++j)
            if(a[j] <= j) f[i] = f[i] < (f[i - a[j]] + 1) ? f[i] : (f[i - a[j]] + 1);
    }
    printf("%d", f[w]);
    return 0;
}