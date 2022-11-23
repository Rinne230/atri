#include<iostream>
#include<stack>
using namespace std;
#define MAXN 1005
typedef long long ll;
char ch[MAXN][MAXN];
int n, m;
int h[MAXN], l[MAXN], r[MAXN];
int st[MAXN], top;
ll ans;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            cin >> ch[i][j];
        }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            h[j] = ch[i][j] == '*' ? 0 : h[j] + 1;
        }
    top = 0;
    for (int i = 1; i <= m; ++i){//顺着求右边小于这个数的位置
        while (top > 0 && h[i] < h[st[top]]){//st[top]作为栈顶指针，作为记录以通过后面输入的i更新r[i-1]的量
            r[st[top]] = i;
            top--;
        }
        top++;
        st[top] = i;
    }
    while (top > 0){
        r[st[top]] = m + 1;
        top--;
    }
    top = 0;
    for (int i = m; i >= 1; i--){//逆着求左边小于等于这个数的位置
        while (top > 0 && h[i] <= h[st[top]]){
            l[st[top]] = i;
            top--;
        }
        top++;
        st[top] = i;
    }
    while (top > 0){
        l[st[top]] = 0;
        top--;
    }
    for (int i = 1; i <= m; ++i){
        ans += ((i - l[i]) * (r[i] - i) * h[i]);
    }
    }
    cout << ans; 
    return 0;
}