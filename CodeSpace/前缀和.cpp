#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001

int A[MAXN], C[MAXN], L[MAXN];
int main(){
    int n, len;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> A[i];
    }
    memcpy(C, A, sizeof(A));
    sort(C, C + n);
    len = unique(C, C + n) - C;
    for (int i = 0; i < n; ++i){
        L[i] = lower_bound(C, C + len, A[i]) - C + 1;
    }
    for (int i = 0; i < n; ++i){
        cout << L[i] << " ";
    }
    return 0;
}