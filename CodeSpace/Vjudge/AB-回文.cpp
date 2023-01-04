#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    int n; 
    cin >> n;
    while (n--){
        string str, ss;
        cin >> str;
        ss = str;
        reverse(str.begin(), str.end());
        if (ss == str) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}