#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    int a, b;
    while (cin >> a >> b){
        string str;
        if (a < 0){
            cout << "-";\
            a = -a;
        }
        while (a){
            int tmp = a % b;
            if (tmp < 10)
                str += (a % b) + '0';
            else str += 'A' + tmp % 10;
            a /= b;
        }
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
}