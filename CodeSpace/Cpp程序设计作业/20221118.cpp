//1
#include <iostream>
using namespace std;
double f(double x){return 2 * x * x + 5 * x + 3;}
int main() {
    double x;
    cin >> x;
    cout << f(x) << endl;
    return 0;
}

//2
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f1(double x){return x * x + 3 * x - 4;}
double f2(double x){return 2 * x + 3;}
double f(double x){
    if (abs(f1(x)) < 1e-5) return x;
    return f(x - f1(x)/f2(x));
}
int main(){
    double x = 0;
    cout << "x=" << f(x) << endl;
    return 0;
}

//3
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x){return x * x + 3 * x - 4;}
int solve(double x){
    if (abs(f(x)) < 1e-5) return 1;
    else if (f(x) > 0) return 2;
    else  return 3;
}
int main(){
    double l, r, mid;
    cin >> l >> r;
    if (l > r) swap(l, r);
    if (l <= -4 && r <= 1){
        while (1){
            mid = (l + r) * 0.5;
            if (solve(mid) == 1) break;
            else if (solve(mid) == 2) l = mid;
            else r = mid;
        }
        cout << "x=" << mid << endl;
    }else{
         while (1){
            mid = (l + r) * 0.5;
            if (solve(mid) == 1) break;
            else if (solve(mid) == 2) r = mid;
            else l = mid;
        }
        cout << "x=" << mid << endl;
    }
    return 0;
}

//4
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x){return x * x + 3 * x - 4;}
int solve(double x){
    if (abs(f(x)) < 1e-5) return 1;
    else if (f(x) > 0) return 2;
    else  return 3;
}
int main(){
    double l, r, mid;
    cin >> l >> r;
    if (l > r) swap(l, r);
    if (l <= -4 && r <= 1){
        while (1){
            mid = (l * f(r) - r * f(l)) / (f(r) - f(l));
            if (solve(mid) == 1) break;
            else if (solve(mid) == 2) l = mid;
            else r = mid;
        }
        cout << "x=" << mid << endl;
    }else{
         while (1){
            mid = (l * f(r) - r * f(l)) / (f(r) - f(l));
            if (solve(mid) == 1) break;
            else if (solve(mid) == 2) r = mid;
            else l = mid;
        }
        cout << "x=" << mid << endl;
    }
    return 0;
}

//5 第二题就已经是递归了