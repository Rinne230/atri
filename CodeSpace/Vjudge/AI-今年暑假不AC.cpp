#include <iostream>
#include <algorithm>
#define maxn 1001
using namespace std;
struct node{
    int s, e;
    friend bool operator < (node a, node b){
        return a.e < b.e;
    }
}pro[maxn];
int n, cnt = 1, curLate = 1;
int main(){
    while(cin >> n){
        if (n == 0) break;
        cnt = 1, curLate = 1;
        for (int i = 1; i <= n; ++i)
            cin >> pro[i].s >> pro[i].e;
        sort(pro + 1, pro + n + 1);
        for (int i = 2; i <= n; ++i){
            if (pro[curLate].e <= pro[i].s){
                ++cnt; curLate = i;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}