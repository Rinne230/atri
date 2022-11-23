//第一题
#include <iostream>
int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", gcd(gcd(a, b), c));
    return 0;
}

//第二题
#include <iostream>
int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    int a, b, c, ans;
    scanf("%d%d%d", &a, &b, &c);
    ans = a * b / gcd(a, b);
    ans = ans * c / gcd(ans, c);
    printf("%d", ans);   
    return 0;
}

//第三题
#include <iostream>
#include <cmath>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
bool isIntact(int num){
    int sum = 0;
    f(i, 1, num - 1) if (num % i == 0) sum = sum + i;
    if (sum == num) return 1;
    return 0; 
}
int main(){
    f(i, 1, 1000) if (isIntact(i)) printf("%d\n", i);
    return 0;
}
