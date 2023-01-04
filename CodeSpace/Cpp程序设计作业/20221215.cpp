#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    str = ' ' + str;
    for (int i = 0; i < str.length(); ++i)
        if (str[i] <= 'z' && str[i] >= 'a' && (str[i - 1] > 'z' || str[i - 1] < 'a'))
            str[i++] -= 'a' - 'A'; 
    for (int i = 1; i < str.length(); ++i) cout << str[i];
    return 0;
}

#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    string str;
    bool flagpre = 1, flagaft = 1;
    int ans = 0;
    getline(cin, str);
    for (int i = 0; i <= str.length(); ++i){
        flagpre = flagaft;
        if (str[i] < 'a' || str[i] > 'z') flagaft = 0;
        else flagaft = 1;
        if (flagpre ^ flagaft) ans++;
    }
    printf("共%d个单词", (ans >> 1) + 1);
    return 0;
}

#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    string str, ans;
    getline(cin, str);
    int a[1001], atop = 0, l, r, mx = 0;
    for (int i = 0; i <= str.length(); ++i)
        if (str[i] < 'a'|| str[i] > 'z')
            a[++atop] = i;
    for (int i = 1; i <= atop; ++i)
        if (a[i] - a[i - 1] > mx){
            mx = a[i] - a[i - 1];
            ans = str.substr(a[i - 1] + 1, a[i] - a[i - 1] - 1);
        }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[1001], b[1001], c[1001];
    int pos;
    cin >> pos;
    for (int i = 1; i <= 10; ++i) {
        cin >> a[i];
    }
    for (int i = pos + 2; i <= 10; ++i) cout << a[i] << " ";
    for (int i = 1; i <= pos + 1; ++i) cout << a[i] << " ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
double fun1(double x){return 1.0 / (2 + sin(x));}
double fun2(double x){return 1.0 / (2 - cos(x));}
double fun3(double x){return (1.0 + x) / (1.0 + x * x);}
double (*ptr[3])(double);
double work(double (*p)(double), double a, double b, int n){
    double ans = 0;
    double h = (b - a) / double(n);
    ans += (p(a) + p(b)) / 2.0;
    for (int i = 1; i <= n - 1; ++i) ans += p(a + i * h);
    return ans * h;
}
int d[3][2] = {{1, 2}, {2, 3}, {2, 4}};
int main(){
    ptr[0] = fun1;
    ptr[1] = fun2;
    ptr[2] = fun3;
    for (int i = 0; i < 3; ++i){
        printf("f%d(x)=\n", i + 1);
        for (int j = 1; j <= 3; ++j)
            printf("n=%d000  %lf\n", j, work(ptr[i], d[i][0], d[i][1], j * 1000));
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool flag[16];
int main(){
    int a[16], sum = 55;
    double ave = 0, mx = 0;
    a[0] = 55;
    for (int i = 1; i <= 15; ++i)
        sum += (a[i] = (15 * a[i - 1] + 97) % 256);
    ave = double(sum) / double(16);
    for (int i = 0; i <= 15; ++i)
        if (abs(double(a[i]) - ave) > abs(mx - ave)) mx = double(a[i]), flag[i] = true;
    printf("%s", "原数组为");
    for (int i = 0; i <= 15; ++i) printf("%d ", a[i]);
    printf("\n最大差值数为%.0lf\n", mx);
    printf("平均值为%.1lf\n", ave);
    printf("%s", "现数组为");
    for (int i = 0; i <= 15; ++i) if(!flag[i])printf("%d ", a[i]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
double avg(int *p){
    int sum = 0;
    for (int i = 0; i < 12; ++i) sum += *(p + i);
    return double(sum) / 12;
}
int mx(int (*p)[4]){
    int maxnum = 0;
    for (int i = 0; i <= 2; ++i){
        for (int j = 0; j <= 3; ++j){
            int tmp = *(*(p + i) + j);
            maxnum = max(maxnum, tmp);
        }
    }
    return maxnum;
}
int mn(int (*p)[4]){
    int minnum = 0x7fffffff;
    for (int i = 0; i <= 2; ++i){
        for (int j = 0; j <= 3; ++j){
            int tmp = *(*(p + i) + j);
            minnum = min(minnum, tmp);
        }
    }
    return minnum;
}
int main(){
    int a[3][4]={{2, 3, 4, 5},{12, 13, 14, 15},{1 ,2, 3, 4}}; 
    cout << "ave=" << avg(a[0]) << endl;
    cout << "max=" << mx(a) << endl;
    cout << "min=" << mn(a) << endl;
    return 0;
}