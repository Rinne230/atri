#include <iostream>
#include <iomanip>
using namespace std;
int n;
inline int  read(){
  int x = 0, f = 1; char ch = getchar();
  while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
  while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
  return x * f;
}
int main(){
    n = read();
    int mx = 0;
    int mi = 0x7fffffff;
    int tmp;
    double sum = 0;
    double tot = (double)n;
    for (int i = 1; i <= n; ++i){
        tmp = read();
        mx = max(mx, tmp);
        mi = min(mi, tmp);
        sum += double(tmp) / tot;
    }
    cout << sum << endl;
    cout << mx << endl << mi << endl;
    cout << fixed << setprecision(2) << sum;  
}