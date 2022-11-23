#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
int n, btop, ctop, T;
bool flag;
int b[maxn << 1], c[maxn << 1], fa[maxn << 1];
struct node{   
    int x, y, z;
}a[maxn];
int find(int x){
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    x = find(x); y = find(y);
    if (x != y)
    fa[x] = y;
}
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        btop = 0, ctop = 0;
        for (int i = 1; i <= n; ++i){
            cin >> a[i].x >> a[i].y >> a[i].z;
            b[++btop] = a[i].x;
            b[++btop] = a[i].y;
        }
        sort(b + 1, b + btop + 1);
        for (int i = 1; i <= btop; ++i){
            if (b[i] != b[i - 1] || i == 1) c[++ctop] = b[i];
        }
        for (int i = 1; i <= n; ++i){
            a[i].x = lower_bound(c + 1, c + ctop + 1, a[i].x) - c;
            a[i].y = lower_bound(c + 1, c + ctop + 1, a[i].y) - c;
        }
        for (int i = 1; i <= ctop; ++i) fa[i] = i;
        for (int i = 1; i <= n; ++i) if (a[i].z) merge(a[i].x, a[i].y);
        flag = true;
        for (int i = 1; i <= n; ++i){
            if (!a[i].z)
                if (find(a[i].x) == find(a[i].y)){
                    flag = false;
                    break;
                }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}