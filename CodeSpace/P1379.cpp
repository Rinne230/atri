#include <bits/stdc++.h>
using namespace std;
int bg, ed = 123804765;
int a[10];
map<int, int> rec[2];//1表示从最终状态开始的搜索
queue<pair<int, bool>> Q;//0表示从初始状态开始的搜索
int change(int x, int op){
    for (int i = 9; i; --i){
        a[i] = x % 10;
        x /= 10;
    }
    int p;
    for (int i = 1; i <= 9; ++i){
        if (a[i] == 0){
            p = i;
            break;
        }
    }
    if (op == 1)
        if (p <= 3) return -1;
        else swap(a[p], a[p - 3]);
    else if (op == 2)
        if (p >= 7) return -1;
        else swap(a[p], a[p + 3]);
    else if (op == 3)
        if ((p % 3) == 1) return -1;
        else swap(a[p], a[p - 1]);
    else if (op == 4)
        if ((p % 3) == 0) return -1;
        else swap(a[p], a[p + 1]);
    x = 0;
    for (int i = 1; i <= 9; ++i) x = x * 10 + a[i];
    return x;
}
void check (int x, pair<int, bool> h){//x表示当前状态
    if (x != -1){
        if (rec[h.second ^ 1].count(x) == true){//1 ^ 1 = 0, 1 ^ 0 = 1
            cout << rec[h.second ^ 1][x] + rec[h.second][h.first] + 1;
            exit(0);
        }else{
            rec[h.second][x] = rec[h.second][h.first] + 1;
            Q.push(make_pair(x, h.second));
        }
    }
}
int main(){
    cin >> bg;
    if (bg == ed) {
        cout << "0";
        return 0;
    }
    Q.push(make_pair(bg, 0));
    Q.push(make_pair(ed, 1));
    while (!Q.empty()){
        int x;
        pair<int, bool> h = Q.front();
        Q.pop();
        x = change(h.first, 1);//向上转移
        check(x, h);
        x = change(h.first, 2);//向下转移
        check(x, h);
        x = change(h.first, 3);//向左转移
        check(x, h);
        x = change(h.first, 4);//向右转移
        check(x, h);
    }
    return 0;
}