#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200010
typedef long long ll;
int s[MAXN];
int main(){
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i){
        cin >> s[i];
    }
    sort(s, s + n);
    int l = 0, r = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i){
        while (s[l] < s[i] - c && l < n) l++;
        while (s[r] <= s[i] - c && r < n) r++;
        if (s[i] - s[l] == c) sum += r - l;
    }
    cout << sum << endl;
    return 0;
}