// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string str;
//     cin >> str;
//     reverse(str.begin(), str.end());
//     cout << str;
// }
#include<bits/stdc++.h>
using namespace std;
int main() {
    int xiao, ge, shi, bai;
    int shibei;
    double shuru, shuchu;
    cin >> shuru;
    shibei = 10 * shuru;//将数字扩成十倍
    bai = shibei / 1000;//取千位
    shi = shibei / 100 - bai * 10;//取百位
    ge = shibei / 10 - bai * 100 - shi * 10;
    xiao = shibei - bai *1000 - shi * 100 - ge * 10;
    shuchu = bai * 0.001 + shi * 0.01 + ge * 0.1 + xiao * 11;
    cout << shuchu << endl;
    return 0;
}