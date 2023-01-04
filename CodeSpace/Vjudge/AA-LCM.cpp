#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}
int main(){
    int a, b, n;
    while (scanf("%d", &n) != EOF){
        cin >> a;
        while (--n){
            cin >> b;
            a = lcm(a, b);
        }
        cout << a << endl;
    }
    return 0;
}