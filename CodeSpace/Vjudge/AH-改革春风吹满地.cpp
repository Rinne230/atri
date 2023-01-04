#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double x[105],y[105];
int main(){
    int n;
    while(cin >> n){
        double s = 0.0;
        if (n == 0) break;
        for(int i = 0;i < n;i++)cin >> x[i] >> y[i];
        x[n] = x[0], y[n] = y[0];
        for(int i = 0;i < n; i++){
            s += x[i] * y[i + 1] - x[i + 1] * y[i];
        }
        cout << fixed << setprecision(1) << abs(s / 2) << endl;
    }
    return 0;
}