#include<iostream>
using namespace std;
int n, a, b;
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b;
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i * i < a; ++i){
            if (a % i == 0) sum1 += i + a / i;
        }
        sum1 -= a;
        for (int i = 1; i * i < b; ++i){
            if (b % i == 0) sum2 += i + b / i;
        }
        sum2 -= b;
        if (sum1 == b && sum2 == a) puts("YES");
        else puts("NO");
    }
}