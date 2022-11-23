#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
int a[110][110], n;
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
int main(){
    n = read();
    f(i, 1, n)
        f(j, 1, n) a[i][j] = read();
    f(k, 1, n)
        f(i, 1, n)
            f(j, 1, n) a[i][j] |= a[i][k] & a[k][j];
    f(i, 1, n){
        f(j, 1, n){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}