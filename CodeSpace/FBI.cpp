#include <bits/stdc++.h>
using namespace std;
int num[201];
string str[201];
int a, b, c, d, e, f;
int main() {
    freopen("名单.in", "r", stdin);
    freopen("本周查寝人员.out", "w", stdout);
    srand(time(0));
    for (int i = 1; i <= 167; ++i) {
        cin >> num[i] >> str[i];
    }
    a = rand() % 8 + 1;
    b = rand() % 32 + 9;
    c = rand() % 10 + 41;
    d = rand() % 54 + 53;
    e = rand() % 11 + 105;
    f = rand() % 52 + 116;
    int x = rand() % 2 + 1;
    if (x == 1) {
        cout << "信管人员\t" << "查的专业" << endl;
        cout << str[a] << '\t' << '\t' << "网安" << endl;
        cout << str[b] << '\t' << '\t' << "网安" << endl;
        cout << "大数据人员\t" << "查的专业" << endl;
        cout << str[c] << '\t' << '\t' << "信管" << endl;
        cout << str[d] << '\t' << '\t' << "信管" << endl;
        cout << "网安人员\t" << "查的专业" << endl;
        cout << str[e] << '\t' << '\t' << "大数据" << endl;
        cout << str[f] << '\t' << '\t' << "大数据" << endl;
    }
    else if (x == 2) {
        cout << "信管人员\t" << "查的专业" << endl;
        cout << str[a] << '\t' << '\t' << "大数据" << endl;
        cout << str[b] << '\t' << '\t' << "大数据" << endl;
        cout << "大数据人员\t" << "查的专业" << endl;
        cout << str[c] << '\t' << '\t' << "网安" << endl;
        cout << str[d] << '\t' << '\t' << "网安" << endl;
        cout << "网安人员\t" << "查的专业" << endl;
        cout << str[e] << '\t' << '\t' << "信管" << endl;
        cout << str[f] << '\t' << '\t' << "信管" << endl;
    }
    return 0;
}