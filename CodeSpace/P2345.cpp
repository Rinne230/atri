#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
typedef long long ll;
ll ans = 0, n;
struct Node{
    int v, x;
}a[maxn], t[maxn];
void mergesort(int l, int r){
    if (l == r) return;
    int mid = (l + r) >> 1;
    mergesort(l, mid), mergesort(mid + 1, r); 
    ll sum1 = 0, sum2 = 0;
    for (int i = l; i <= mid; ++i){sum1 += a[i].x;}
    for (int i = mid + 1; i <= r; ++i){sum2 += a[i].x;}
    int p1 = l, p2 = mid + 1, cnt = 0;
    while (p1 <= mid && p2 <= r){
        if (a[p1].v >= a[p2].v){//v从大到小排
            t[++cnt] = a[p1];
            ans += a[p1].v * abs(sum2 - (r - p2 + 1) * a[p1].x);
            //a[p1]的响度 * 所有响度不如a的牛的距离差的和      
            sum1 -= a[p1++].x;
        }else{
            t[++cnt] = a[p2];
            ans += a[p2].v * abs(sum1 - (mid - p1 + 1) * a[p2].x); 
            sum2 -= a[p2++].x;
        }
        //因为v从大到小排，扫描自左到右扫，当某个值大于扫描的头，则大于所有后面的v
    }
    while (p1 <= mid) t[++cnt] = a[p1++];
    while (p2 <= r) t[++cnt] = a[p2++];
    for (int i = l; i <= r; ++i) a[i] = t[i - l  + 1];
}
bool cmp(Node p, Node q) {return p.x < q.x;}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].v >> a[i].x;
    sort(a + 1, a + n + 1, cmp);
    mergesort(1, n);
    cout << ans;
    return 0;
}