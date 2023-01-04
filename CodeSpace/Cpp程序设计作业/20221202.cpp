#include <bits/stdc++.h>
#include <cstdio>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
int main(){
    int mx = -0x7fffffff;
    int idx, idy;
    f(i, 1, 4) 
        f(j, 1, 4) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp > mx){
                mx = tmp;
                idx = i;
                idy = j;
            }
        }
    printf("第%d行第%d列是最大数%d", idx, idy, mx);
    return 0;
}


#include <bits/stdc++.h>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
struct Mat{
    int a[5][5];
    Mat T(){
        Mat Ts;
        f(i, 1, 4)
            f(j, 1, 4)
                Ts.a[i][j] = a[j][i];
                return Ts;
    }
}Or, Res;
int main(){
    f(i, 1, 4)
        f(j, 1, 4)  scanf("%d", &Or.a[i][j]);
    Res = Or.T();
    f (i, 1, 4){
        f(j, 1, 4){
            printf("%d ", Res.a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

#include <bits/stdc++.h>
#define f(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
int a[10][10];
int main(){
    f(i, 1, 9)
        f(j, 1, 9){
            a[i][j] = i * j; 
            if (i == j) break;
        }
    f(i, 1, 9){
        f(j, 1, 9){
            printf("%d*%d=%d ", i, j, a[i][j]);
            if (i == j) break;
        }
        putchar('\n');
    }
    return 0;
}