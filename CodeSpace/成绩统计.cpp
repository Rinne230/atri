#include <iostream>
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
  int tmp;
  double tot = (double)n;
  double cnt1 = 0, cnt2 = 0; 
  int cnt11 = 0, cnt22 = 0;
  for (int i = 1; i <= n; ++i){
    tmp = read();
    if (tmp >= 60) cnt1 = cnt1 + 1.0, cnt11++;
    if (tmp >= 85) cnt2 = cnt2 + 1.0, cnt22++;
  }
  double rate1, rate2, rate11, rate22;
  rate1 = cnt1 / tot;
  rate2 = cnt2 / tot;
  rate11 = (double)cnt11 / n;
  rate22 = (double)cnt22 / n;
  if (rate1 - rate11 >= 0.005) rate1 += 0.01;
  if (rate2 - rate22 >= 0.005) rate2 += 0.01;
  printf("%.0lf%%\n%.0lf%%", 100.0 * rate1, 100.0 * rate2);
  return 0;
}