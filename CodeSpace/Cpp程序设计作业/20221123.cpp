//第一题
#include <iostream>
using namespace std;
bool vis[201];
int p[201];
int main(){
    int cnt = 0, top = 0;
    for (int i = 2; i <= 200; ++i){
        if (!vis[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= 200; ++j){
            vis[i * p[j]] = 1;
            if (!(i % p[j])) break;
        }
    }
    for (int i = 100; i <= 200; ++i){
        if(!vis[i]) {
            ++top;
            printf("%d ", i);
            if(top % 5 == 0) printf("\n");
        }
    }
    return 0;
}

//第二题
#include <iostream>
using namespace std;
bool vis[10001];
int p[10001], ans[10001],  num;
int main(){
    int cnt = 0, top = 0;
    cin >> num;
    for (int i = 2; i <= num; ++i){
        if (!vis[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= num; ++j){
            vis[i * p[j]] = 1;
            if (!(i % p[j])) break;
        }
    }
    for (int i = 1; i <= cnt; ++i){
        if (num % p[i] == 0)
            ans[++top] = p[i];
    }
    for (int i = 1; i <= top; ++i) printf("%d ", ans[i]);
    return 0;
}

//第三题
#include <iostream>
using namespace std;
bool vis[10001];
int p[10001], ans[10001],  num;
int main(){
    int cnt = 0;
    cin >> num;
    for (int i = 2; i <= num; ++i){
        if (!vis[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= num; ++j){
            vis[i * p[j]] = 1;
            if (!(i % p[j])) break;
        }
    }
    for (int i = 1; i <= cnt && p[i]; ++i) if (!vis[num - p[i]] && p[i] <= num - p[i]) printf("%d=%d+%d\n", num, p[i], num - p[i]);
    return 0;
}

//第四题
#include <cstdio>
#include <iostream>
using namespace std;
int fun(int n){
    int mul = 1;
    while(n){
        mul *= (n % 10);
        n /= 10;
    }
    return mul;
}
int main(){
    int n; int mul;
    cin >> n;
    while (n){
        mul = fun(n);
        printf("%d的各位数之积为%d\n", n, mul);
        cin >> n;
    }
    return 0;
}