#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
int a[100005];
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int, vector<int>, less<int>> q2;
int main(){
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF){
        int num = 0;
        for (int i = 0; i < n; ++i) a[i] = read();
        for (int i = 1; i <= m; ++i){
            int u = read();
            while (num < u){
                q1.push(a[num]);
                if (!q2.empty() && q1.top() < q2.top()){
                    int tmp = q1.top();
                    q1.pop();
                    q2.push(tmp);
                    q1.push(q2.top());
                    q2.pop();
                }
                num++;
            }
            printf("%d\n", q1.top());
            q2.push(q1.top());
            q1.pop();
        }
    }
    return 0;
}