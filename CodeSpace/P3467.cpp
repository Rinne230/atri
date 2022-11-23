#include <bits/stdc++.h>
using namespace std;
int stk[250001];
int d, w, num; 
long long top = 0; 
int n;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> d >> w;
        while (top > 0 && w <= stk[top]){
            if (w == stk[top]) num++;
            top--;
        }
        stk[++top] = w;
    }
    cout << n - num << endl;
    return 0;
}