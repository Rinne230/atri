#include <vector>
#include <array>
#include <iostream>
int n, ans;
using namespace std;
vector<int> stk;
array<unsigned long long, 1000005> a;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a.at(i);
    while (stk.size() && (a.at(i) >= a.at(stk.back()))) {
      ans ^= stk.back();
      stk.pop_back();
    }
    stk.push_back(i);
    ans ^= i;
    cout << ans << '\n';
  }
  return 0;
}