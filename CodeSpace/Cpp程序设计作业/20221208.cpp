#include<bits/stdc++.h>
using namespace std;
int a[8] = {26, 1007, 956, 705, 574, 371, 416, 517};
int b[8] = {994, 631, 772, 201, 262, 763, 1000, 781};
int c[8];
int main(){
    for (int i = 0; i < 8; ++i)
        c[i] = __gcd(a[i], b[i]);
    for (int i = 0; i < 8; ++i)
        cout << c[i] << " ";
    return 0;
}

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
struct node{
    ll num;
    ll sum(){
        ll x = num, tmp = 0;
        while(x){
            tmp += x % 10;
            x /= 10;
        }
        return tmp;
    }
}c[11];
int main(){
    ll ans = 0;
    puts("请输入10个整数");
    for (int i = 1; i <= 10; ++i) {
        scanf("%lld", &c[i].num);
        ans = ans + c[i].num;
    }
    printf("sum=%lld\n", ans);
    //printf("%lld\t%lld\n", c[i].num, c[i].sum());
    for (int i = 1; i <= 10; ++i) cout << c[i].num << '\t' << c[i].sum() << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool isten(int x){
    int sum = 0;
    while (x){
        sum += x % 10;
        x /= 10;
    }
    if (sum == 10) return 1;
    return 0;
}
int main(){
    int num, top = 0;
    int c[101];
    scanf("%d", &num);
    for (int i = 100; i <= num; ++i)
        if (isten(i)) 
            c[++top] = i;
    printf("%d以内各位数和为10的三位数共有%d个\n", num, top);
    for (int i = 1; i <= top; ++i){
        printf("%d\t", c[i]);
        if (!(i % 8)) putchar('\n');
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool isprime(int x){
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false;
    return true;
}
int main(){
    int n, top = 0;
    while(scanf("%d", &n) && n){
        if(isprime(n)) {printf("%d\t", n); ++top;}
    }
    printf("\n原数据中有%d个素数", top);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[]={2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
int main(){
    int n, mid;
    scanf("%d", &n);
    int l = 0, r = 11;
    bool flag = false;
    while (l < r){
        mid = (l + r) >> 1;
        if (a[mid] == n){
            flag = true;
            break;
        }
        else if (a[mid] > n) r = mid;
        else if (a[mid] < n) l = mid + 1;
    }
    if (flag) printf("该数在数组中的序号为%d", mid);
    else puts("数组中没有该元素");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[] = {0, 2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 6, 7, 7, 8, 9, 9, 10, 10, 10};
int main(){
    for (int i = 1; i <= 19; ++i)
        if(a[i] != a[i - 1]) printf("%d ", a[i]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[101], btop, n;
int main(){
    while (cin >> n && n) a[++btop] = n;
    sort(a + 1, a + btop + 1);
    for (int i = 1; i <= btop; ++i) printf("%d ", a[i]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[]={5, 26, 98, 77, 1, 27, 30};
int cnt[10];
void work(int x){
    while(x){
        cnt[x % 10]++;
        x /= 10;   
    }
}
int main(){
    for (int i = 0; i < 7; ++i) work(a[i]);
    cout << "数组数据为" << endl;
    for (int i = 0; i < 7; ++i){
        cout << a[i] << " ";
    }
    cout << "\n数字0到9出现的次数分别为" << endl;
    for (int i = 0; i < 10; ++i) printf("%d\t%d\n", i, cnt[i]);
    return 0;
}