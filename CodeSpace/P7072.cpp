#include <iostream>
using namespace std;
int t[601], n, w, sum;
int main(){
    int tmp;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i){
        cin >> tmp;
        t[tmp]++;
        sum = 0;
        for (int j = 600; j >= 0; --j){
            sum += t[j];
            if (sum >= max(1, i * w / 100)){
                cout << j << " ";
                break;    
            } 
        }
    }
    return 0;
}