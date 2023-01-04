#include <bits/stdc++.h>
#include <regex>
using namespace std;
class Rect{
    private:
        int a = 2, b = 3, h = 4;
    public:
        int Areas(){return 2 * (a * b + b * h + a * h);}
        int Volumn(){return a * b * h;}
        void showabh(){
            cout << "长为" << a << " 宽为" << b << " 高为" << h << endl;
        }
};
class Cub:private Rect{
    private:
        int s, v;
    public:
        void show(){
            s = Areas();
            v = Volumn();
            showabh();
            cout << "表面积为" << s << " 体积为" << v << endl;
        }
};
int main(){
    Cub cub;
    cub.show();
    return 0;
}

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
class ARR{
    private:
        int n;
        int a[100];
        int mx = 0, maxindex;
    public:
        ARR(int x[], int size){
            for (int i = 0; i < size; ++i) a[i] = x[i];
            n = size;
        }
        int FindMax(){
           for (int i = 0; i < n; ++i){
               if (a[i] > mx){
                   maxindex = i;
                   mx = a[i];
               }
           } 
           return maxindex;
        }
        void show(){
            for (int i = 0; i < n; ++i){
                if (i % 5 == 0) putchar('\n');
                cout << a[i] << '\t';
            }
            putchar('\n');
            cout << "max=" << a[FindMax()] << '\t' << "maxindex=" << FindMax() + 1;
        }
};
int main(){
    int b[] = {3, 4, 6, 8, 10, 34, 2};
    ARR arr(b, sizeof(b) / sizeof(int));
    arr.show();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
class NUM{
    private:
        int a[20];
        int count;
    public:
        NUM(){count = 0;}
        int reverse(int n){
            int x = 0;
            while (n){
                x = (x << 3) + (x << 1) + n % 10;
                n /= 10;
            }
            return x;
        }
        int isPrime(int n){
            for (int i = 2; i * i < n; ++i)
                if (n % i == 0) return 0;
            return 1;
        }
        void fun(){
            for (int i = 10; i <= 100; ++i)
                if (isPrime(i) && isPrime(reverse(i)))
                    a[count++] = i;
        }
        void show(){
            cout << "count=" << count << endl;
            for (int i = 0; i < count; ++i){
                cout << a[i] << " ";
            }
        }
};
int main(){
    NUM num;
    num.fun();
    num.show();
    return 0;
}

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class ARRAY{
    private:
        int a[100];
        int n;
    public:
        ARRAY(int t[], int m){
            n = m;
            for (int i = 0; i < n; ++i) a[i] = t[i];
        }
        int sum(int x){
            int tmp = 0;
            while(x){
                tmp += x % 10;
                x /= 10;
            }
            return tmp;
        }
        void fun(){
            for (int i = 1; i <= n - 1; ++i){
                for (int j = 0; j < n - i; ++j)
                    if (sum(a[j]) > sum(a[j + 1]))
                        swap(a[j], a[j + 1]);
            }
        }
        void show(){
            puts("排序前的数组为");
            for (int i = 0; i < n; ++i)
                cout << a[i] << " ";
            putchar('\n');
            fun();
            puts("排序后的数组为");
            for (int i = 0; i < n; ++i)
                cout << a[i] << " ";
        }
};
int main(){
    int b[] = {297, 735, 624, 158, 312, 900};
    ARRAY arr(b, 6);
    arr.show();
}

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
class ARR{
    private:
        int n, a[100];
    public:
        ARR(int x[], int size){
            n = size;
            for (int i = 0; i < n; ++i){
                a[i] = x[i];
            }
        }
        void delsame(){
            int btop = 0;
            int b[100];
            b[btop++] = a[0];
            for (int i = 1; i < n; ++i)
                if(a[i] != a[i - 1]) b[btop++] = a[i];
            n = btop;
            for (int i = 0; i < n; ++i) a[i] = b[i];
        }
        void show(){
            puts("原数据");
            for (int i = 0; i < n; ++i) cout << a[i] << " ";
            putchar('\n');
            delsame();
            puts("结果数据");
            for (int i = 0; i < n; ++i) cout << a[i] << " ";
        }
};
int main(){ 
    int a[] = {1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 8, 9, 10, 10};
    ARR arr(a, sizeof(a) / sizeof(int));
    arr.show();
    return 0;   
}