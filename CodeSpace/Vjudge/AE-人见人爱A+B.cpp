#include <iostream>
using namespace std;
int ah, am, as, bh, bm, bs;
int ch, cm, cs;
int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> ah >> am >> as >> bh >> bm >> bs;
        ch = ah + bh, cm = bm + am, cs = as + bs;
        cm += cs / 60;
        cs %= 60;
        ch += cm / 60;
        cm %= 60;
        cout << ch << " " << cm << " " << cs << endl;
    }
    return 0;
}