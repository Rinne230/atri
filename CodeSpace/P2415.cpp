#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[31], n, b;
ll sum;
int main(){
    while(cin >> a[n++]);
    for (int i = 0; i < n; ++i){
        sum += a[i];
    }
    sum *= pow(2, n - 2);
    cout << sum;
    return 0;
}