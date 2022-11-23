#include<bits/stdc++.h>
using namespace std;
int y1, y2, n, m;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
int main(){
    n = read(), y1 = read();
    m = read(), y2 = read();
    
    return 0;
}