//第一题
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double x, t1, t2;
bool solve (){
    if (abs(t2 - t1) < 1e-5) return true;
    double tmp = (double) t2 * 2 / 3 + x / (t2 * t2 * 3);
    t1 = t2; t2 = tmp;
    return solve();
}
int main(){
    scanf("%lf", &x);
    t1 = x; t2 = t1 * 2 / 3 + t1 / (t1 * t1 * 3);
    if (solve()) cout << "y=" << t2 << endl;
    return 0;
}


//第二题
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// using namespace std;
// double fac[101];
// double sqr[101];
// int n;
// double x;
// double ans;
// int main(){
//     scanf("%d%lf", &n, &x);
//     fac[1] = 1; sqr[1] = x;
//     for (int i = 2; i < (n << 1); ++i) fac[i] = fac[i - 1] * i;
//     for (int i = 2; i < (n << 1); ++i) sqr[i] = sqr[i - 1] * x;
//     for (int i = 1, j = 1; i < (n << 1); i += 2, j = -j) ans += (double)j * sqr[i] / fac[i];
//     printf("y=%lf", ans);
//     return 0;
// }
