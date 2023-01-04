#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int flag = 0;
int lowbit(int x) {return x & (-x);}
int sum(int flag){
    int cnt = 0;
    for (int i = 1; i <= (1 << 3); i += lowbit(i))
        if (flag & i) cnt++; 
    return cnt;
}
int main(){
    int n;
    string str;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        flag = 0;
        cin >> str;
        if (str.length() < 8 || str.length() > 16) {
            puts("NO");
            continue;
        }
        for(int i = 0; i < str.length(); ++i){
            if (str[i] >= 'A' && str[i] <= 'Z') flag |= 1;
            else if (str[i] >= '0' && str[i] <= '9') flag |= (1 << 1);
            else if (str[i] >= 'a' && str[i] <= 'z') flag |= (1 << 2);
            else if (str[i] == '~' || str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '^') flag |= (1 << 3);
        }
        if (sum(flag) >= 3) puts("YES");
        else puts("NO");
    }
    return 0;
}