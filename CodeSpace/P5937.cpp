#include <bits/stdc++.h>
using namespace std;
#define maxn 200001
struct  Node{
    int x, y, z;
}a[maxn];
//1. 如果 [l,r][l,r] 有偶数个 11 ，那么 sum[l-1]sum[l−1] 和 sum[r]sum[r] 奇偶性相同
//2. 如果 [l,r][l,r] 有奇数个 11 ，那么 sum[l-1]sum[l−1] 和 sum[r]sum[r] 奇偶性相反
//f[i]表示与自己奇偶性相同的集合
//f[i + n]表示与自己奇偶性不同的集合
int f[maxn], b[maxn], btop, ctop, n, m;
map<int, int> Map;
int findx(int x){return f[x] == x ? x : f[x] = findx(f[x]);}
void merge(int x, int y){
    int x1 = findx(x);
    int x2 = findx(y);
    if(x1 != x2) f[x1] = x2;
}
int main(){
    string str;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> a[i].x >> a[i].y >> str;
        a[i].x--;
        a[i].z = (str[0] == 'o') ? 1 : 0;
        b[++btop] = a[i].x;
        b[++btop] = a[i].y;
    }   
    sort(b + 1, b + btop + 1);
    b[0] = -0x7ffffff;
    for (int i = 1; i <= btop; ++i) if(b[i] != b[i - 1]) Map[b[i]] = ++ctop;
    for (int i = 1; i <= ctop * 2; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i){
        a[i].x = Map[a[i].x];
        a[i].y = Map[a[i].y];
        if (a[i].z == 0){
            if (findx(a[i].x) == findx(a[i].y + ctop)){
                cout << i - 1;
                return 0;
            }
            else{
                merge(a[i].x, a[i].y);
                merge(a[i].x + ctop, a[i].y + ctop);
            }
        }else{
            if (findx(a[i].x) == findx(a[i].y)){
                cout << i - 1;
                return 0;
            }else{
                merge(a[i].x, a[i].y + ctop);
                merge(a[i].x + ctop, a[i].y);
            }
        }
    }
    cout << m;
    return 0;
}