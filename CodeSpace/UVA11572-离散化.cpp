#include <bits/stdc++.h>
using namespace std;
int T, N, num, tot;
#define MAXN 1000010
int A[MAXN], C[MAXN], L[MAXN], sum[MAXN], cnt[MAXN], len, ans;
void init(){
    memset(A, 0, sizeof(A));
    memset(C, 0, sizeof(C));
    memset(L, 0, sizeof(L));
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    num = 0;
    tot = 0;
    ans = 0;
}
int main() {
    cin >> T >> N;
    while (T--){
        init();
        for (int i = 0; i < N; ++i){
            cin >> A[i];}
        memcpy(C, A, sizeof(A));
        sort(C, C + N);
        len = unique(C, C + N) - C;
        for (int i = 0; i < N; ++i){L[i] = lower_bound(C, C + len, A[i]) - C + 1;}
        for (int i = 0; i < N; ++i){
            cnt[L[i]]++;
            if (cnt[L[i]] == 1) tot++;  
        }
        int l = 0, r = 0;
        // for (int i = 0; i < N; ++i) cout << L[i] << " ";
        // cout << endl;
        while(l <= r && r < N){
            if (num < tot){
                r++;
                sum[L[r - 1]]++;
                if (sum[L[r - 1]] == 1) num++;
            }else{
                if (num == tot) ans = (r - l > ans) ? r - l : ans;
                sum[L[l]]--;
                if (sum[L[l]] == 0) num--;
                l++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}