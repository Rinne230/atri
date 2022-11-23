//author:atrilactose
//date:20221109
//
//第一题
#include <bits/stdc++.h>
using namespace std;
typedef float f;
int main(){
    f a, b, c;
    cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || b + c <= a) {
         cout<<"Not Triangle\n";
         return 0;
    }
    cout<<"Triangle\n";
    return 0;
}

//第二题
#include <iostream>
using namespace std;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
int main(){
    int x = read();
    if ((!(x % 4) && (x % 100)) || !(x % 400)){
        printf("%d is a leap year", x);
        return 0;
    }
    printf("%d isn't a leap year", x);
    return 0;
}

//第三题
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
double opt1, opt2 ,ans;
char ch;
bool flag;
int main(){
    cin >> opt1 >> ch >> opt2;
    switch (ch)
    {
    case '*':
        ans = opt1 * opt2;
        break;
    case '-':
        ans = opt1 - opt2;
        break;
    case '+':
        ans = opt1 + opt2;
        break;
    default:
        cout<<"输入错误的运算符!\n";
        return 0;
    }
    cout << opt1 << ch << opt2 << '=' << ans << endl;
    return 0;
}

//第四题
#include <iostream>
#include <cmath>
using namespace std;
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
int dlt(int a, int b, int c){return b * b - 4 * a * c;}
pair<int, int> ans2(int a, int b, int c){
    int x1, x2;
    x1 = (-b + sqrt(dlt(a, b, c))) / (2 * a);
    x2 = (-b - sqrt(dlt(a, b, c))) / (2 * a);
    return make_pair(x1, x2);
}
int main(){
    int a = read(), b = read(), c = read();
    if (dlt(a, b, c) < 0) {printf("%s", "方程无实根！"); return 0;}
    else if (dlt(a, b, c) > 0) {
        pair<int, int> ans = ans2(a, b, c);
        printf("方程有两个不同的实根：x1=%d，x2=%d", ans.first, ans.second);
        return 0;
    }
    pair<int, int> ans = ans2(a, b, c);
    printf("方程有两个相等的实根：x=%d", ans.first);
    return 0;
}

//第五题
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
double opt1, opt2 ,ans;
char ch;
bool flag;
int main(){
    cin >> opt1 >> ch >> opt2;
    switch (ch){
    case '*':
        ans = opt1 * opt2;
        break;
    case '-':
        ans = opt1 - opt2;
        break;
    case '+':
        ans = opt1 + opt2;
        break;
    case '/':
        if (!opt2){cout << "除数不能为0！"; return 0;}
        ans = opt1 / opt2;
        break;
    default:
        cout<<"输入错误的运算符！";
        return 0;
    }
    cout << opt1 << ch << opt2 << '=' << ans << endl;
    return 0;
}
