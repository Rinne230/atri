#include <bits/stdc++.h>
using namespace std;
#define maxn 500010
struct  Node{
    double x, y;
}p[maxn], O;//储存点和圆心
int n;
double r;
double dis(Node a, Node b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
void circle(Node p1, Node p2, Node p3){
    double a, b, c, d, e, f;
    a = p1.x - p2.x; b = p1.y - p2.y;
    c = p1.x - p3.x; d = p1.y - p3.y;
    e = (p1.x * p1.x - p2.x * p2.x - p2.y * p2.y + p1.y * p1.y) / 2;
    f = (p1.x * p1.x - p3.x * p3.x - p3.y * p3.y + p1.y * p1.y) / 2;
    O.x = (b * f - d * e) / (b * c - a * d);
    O.y = (c * e - a * f) / (b * c - a * d);
    r = dis(O, p1);
}
int main(){
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
    random_shuffle(p + 1, p + n + 1);
    O = p[1], r = 0;
    for(int i = 2; i <= n; ++i){
        if (dis(p[i], O) > r){
            O = p[i], r = 0;
            for (int j = 1; j <= i - 1; ++j){
                if (dis(O, p[j]) > r){
                    O.x = (p[i].x + p[j].x) / 2;
                    O.y = (p[i].y + p[j].y) / 2;
                    r = dis(O, p[j]);
                    for (int k = 1; k <= j - 1; ++k){
                        if (dis(O, p[k]) > r){
                            circle(p[i], p[j], p[k]);
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(10) << r << endl << O.x << " " << O.y;
    return 0;
}
