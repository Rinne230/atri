#include<bits/stdc++.h>
using namespace std;
int a[1010][1010], n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
    for (int i = n; i > 1; --i)
        for (int j = 1; i <= i - 1; ++j)
            a[i - 1][j] += max(a[i][j], a[i][j + 1]);
    printf("%d", a[1][1]);
    return 0;
}