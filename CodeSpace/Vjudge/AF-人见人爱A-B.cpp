#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m, n;
    int a[101], b[101], c[101];
    while (cin >> n >> m && (m || n)){
        int cnt = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i){cin >> a[i];}
        for (int i = 1; i <= m; ++i){cin >> b[i];}
        for (int i = 1; i <= n; ++i){
            bool flag = true;
            for (int j = 1; j <= m; ++j)
                if (a[i] == b[j]) {flag = false; break;}
            if (flag) c[++cnt] = a[i];
        }
        if (!cnt) {puts("NULL"); continue;}
        sort(c + 1, c + cnt + 1);
        for (int i = 1; i <= cnt; ++i){
            cout << c[i] << " ";
        }
        cout << endl;
    }
}