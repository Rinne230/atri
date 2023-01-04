#include <bits/stdc++.h>
#include <cstdio>
#include <sstream>
using namespace std;
stringstream ss;
string str;
int ans;
int main(){
    cin >> str;
    ss << str;
    ss >> ans;
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
string str;
int a, to, b;
int main(){
    cin >> a >> to;
    b = a;
    while (a){
        if (to == 16 && (a % 16) >= 10)
            str = char((a % to) - 10 + 'A') + str;
        else
            str = char((a % to) + '0') + str;
        a /= to;
    }
    printf("十进制数%d转换成%d进制数的结果为%s", b, to, str.c_str());
    return 0;
}

#include <bits/stdc++.h>
#include <string>
using namespace std;
string str;
int b[101], btop;
int main(){
    getline(cin, str);
    for(int i = 0; i < str.length(); ++i){
        int x = 0;
        while (str[i] <= '9' && str[i] >= '0'){
            x = (x << 3) + (x << 1) + (str[i++] - '0');
        }
        if(x)
            b[++btop] = x;
    }
    for (int i = 1; i <= btop; ++i) cout << b[i] << " ";
    return 0;
}

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int fun(char *str,char *substr){
    int n = 0;
    char *p , *r;
    while(*str){
        p = str;
        r = substr;
        while(*r)
           if (*r == *p) {r++;  p++; }
           else  break;
        if (*r == '\0') n++;
        str++;
    }
    return  n;
}
int main(){
    char str[101], substr[101];
    cin.getline(str, 100);
    cin >> substr;
    cout << "n=" <<  fun(str, substr);
    return 0;
}

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
class T{
    double a, b, c;
    public:
        void Tri(double x, double y, double z){
            a = x, b = y, c = z;
        }
        double Peri(){
            return a + b + c;
        }
        double Area(){
            double t = (a + b + c) / 2;
            double s = sqrt(t * (t - a) * (t - b) * (t - c));
            return s;
        }
        void Show(){
            cout << "当三角形的边长是" << a << "、" << b << "和" << c << endl;
            cout << "三角形的周长是" << Peri() << endl;
            cout << "三角形的面积是" << Area() << endl;
        }
};
int main(){
    T tri1, tri2;
    tri1.Tri(3, 4, 5);
    tri2.Tri(5, 6, 7);
    tri1.Show();
    tri2.Show();
    return 0;
}

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
class NUM{
    int n, *p;
    public:
        NUM(int n1){
            n = n1;
            p = new int[n];
        }
        int yes(int x){
            for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 1;
            return 0;
        }
        void fun(){
            for (int i = 3; ; ++i){
                int j = 0;
                while (yes(i) && j < n){
                    p[j] = i;
                    ++j;
                    ++i;
                }
                if (j == n) break;
            }
        }
        void print(){
            for (int i = 0; i < n; ++i)
                cout << p[i] << " ";
            cout << endl;
        }
        ~NUM(){
            if(p) delete [] p;
        }
};
int main(){
    NUM num(10);
    num.fun();
    num.print();
    return 0;
}

#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int a[27];
class STR{
    char *s1;
    char *s2;
    int s2top = 0;
    public:
        STR(char *str){
            int len = strlen(str);
            s1 = new char[len + 1];
            s2 = new char[len + 1];
            strcpy(s1, str);
            strcpy(s2, "\0");
        }
        void delsame(){
            for (int i = 0; i < strlen(s1); ++i){
                bool flag = false;
                for (int j = 0; j < strlen(s2); ++j){
                    if (*(s1 + i) == *(s2 + j)) flag = true;
                }
                if (!flag) *(s2 + s2top++) = *(s1 + i);
            }
        }
        void show(){
            cout << "s1=" << s1 << endl << "s2=" << s2 << endl;
        }
        ~STR(){
            if (s1)
                delete [] s1;
            if (s2)
                delete [] s2;
        }
};
int main(){
    STR test("concoon");
    test.delsame();
    test.show();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
class Circle{
    int num[40] = {41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36}, Max[4], Min[4];
    int sum_max = 0;
    int sum_min = 0x7fffffff;
    public:
        Circle(){
            srand(time(NULL));
            //for(int i = 0;i < 20; i++) num[i] = num[i + 20] = rand() % 100;
            for(int i = 0;i < 20; i++) num[i + 20] = num[i];
        }
        void Find_Max(){
            for (int i = 0; i <= 19; ++i){
                int sum = 0;
                for (int j = 0; j <= 3; ++j){
                    sum += num[i + j];
                }
                if (sum > sum_max){
                    sum_max = sum;
                    for (int j = 0; j <= 3; ++j) Max[j] = num[i + j];
                }
                if (sum < sum_min){
                    sum_min = sum;
                    for (int j = 0; j <= 3; ++j) Min[j] = num[i + j];
                }
            }
        }
        void Show(){
            for (int i = 0; i < 20; ++i) printf("%d ", num[i]);
            putchar('\n');
            printf("Max=%d", sum_max);
            putchar('\n');
            for (int i = 0; i <= 3; ++i) printf("%d ", Max[i]);
            putchar('\n');
            printf("Min=%d", sum_min);
            putchar('\n');
            for (int i = 0; i <= 3; ++i) printf("%d ", Min[i]);
        }
};
int main(){
    Circle num;
    num.Find_Max();
    num.Show();
    return 0;
}