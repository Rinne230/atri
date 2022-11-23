//author:atrilactose
//date:20221111
//第一题
#include <iostream>
#define f(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
int main(){
    int x = 30, y = 90;
    pair<int, int> ans;
    f(i, 0, x) if (i * 2 + (x - i) * 4 == y) ans.first = i, ans.second = x - i;
    printf("鸡：%d，兔：%d", ans.first, ans.second);
    return 0;
}
//第二题
#include <iostream>
using namespace std;
#define f(i, a, b) for(int i = (a); i <= (b); ++i)
struct node{
    int x, y, z;
}ans;
int main(){
    f(i, 0, 36)
        f(j, 0, 36)
            if (i * 8 + j * 4 + 36 - i - j == 72)
                ans.x = i, ans.y = j, ans.z = 36 - i - j;
    printf("男人：%d，女人：%d，儿童：%d", ans.x, ans.y, ans.z);
    return 0;
}
//第三题
#include <iostream>
using namespace std;
#define f(i, a, b, c) for(int i = (a); i <= (b); i += (c))
int main(){
    int cnt = 0;
    f(i, 3, 599, 3){
        int x = i; 
        bool flag = false;
        while (x) {
            if (x % 10 == 5) {flag = true; break;}
            x /= 10;
        }
        if (flag) {
            printf("%10d", i);
            if (++cnt % 10 == 0) printf("\n");
        }
    }
    return 0;
}
//第四题
#include <iostream>
#define f(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x += ch - '0'; ch = getchar();}
    return x * f;
}
int main(){
    printf("%d", read());
    return 0;
}