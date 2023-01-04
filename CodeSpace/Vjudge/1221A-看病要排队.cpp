#include <bits/stdc++.h>
using namespace std;
struct patient{
    int pri;
    int idx;
}peo;
bool operator < (const patient a, const patient b) {
    if (a.pri != b.pri) return a.pri < b.pri;
    return a.idx > b.idx;
}
int main(){
    int n, idx, pri;
    string str;
    while (scanf("%d", &n) != EOF){
        int top = 1;
        priority_queue<patient> q[4]; 
        while (n--) {
            cin >> str >> idx;
            if (str == "IN"){
                cin >> pri;
                peo.pri = pri;
                peo.idx = top++;
                q[idx].push(peo);
            }
            else{
                if (!q[idx].empty()){
                    cout << q[idx].top().idx << endl;
                    q[idx].pop();
                } else puts("EMPTY");
            }
        }
    }
    return 0;
}