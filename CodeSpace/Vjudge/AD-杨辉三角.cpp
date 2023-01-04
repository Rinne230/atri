#include <iostream>
using namespace std;
typedef long long ll;
ll a[31][31], n;
int main(){
    a[1][1] = 1;
    for (int i = 2; i <= 30; ++i){
        for (int j = 1; j <= i; ++j){
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    while (cin >> n){
       for (int i = 1; i <= n; ++i){
           for (int j = 1; j <= i; ++j){
               if (j != 1) cout << " ";
               cout << a[i][j];
           }
           cout << endl;
       }
       cout << endl;
    }
    return 0;
}