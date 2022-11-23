#include<iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define maxn 100010
int n;
double a[maxn], b[maxn];
double maxnum = 0;
double suma, sumb;
bool cmp(double x, double y){
    return x > y;
}
bool judge(int l, int r){
    double cur = min(suma, sumb) - l - r + 1;
    if (min(suma, sumb + b[r]) - l - r > cur) return 1;
    else return 0;
}
int main(){
    int r = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int l = 1; l <= n; ++l){
        suma += a[l];
        while(judge(l, r) && r <= n) sumb += b[r++];
        maxnum = max(maxnum, min(suma, sumb) - l - r + 1);
    }
    cout << fixed << setprecision(4) << maxnum << endl;
    return 0;
}