#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
struct  Node{
    double x, y;
}p[maxn], q[maxn], O;//储存点和圆心
double dis(Node a, Node b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double r, eps = 1e-10;
int n, m, res[maxn][2], cnt, ci;
void work(int l, int r){
    int qtop = 0;
    for (int i = l; i <= r; ++i){
        q[++qtop] = p[i];
    }
    random_shuffle(q + 1, q + qtop + 1);
    O = q[1], r = 0;
    for(int i = 2; i <= n; ++i){
        if (dis(q[i], O) > r){
            O = q[i], r = 0;
            for (int j = 1; j <= i - 1; ++j){
                if (dis(O, q[j]) > r){
                    O.x = (q[i].x + q[j].x) / 2;
                    O.y = (q[i].y + q[j].y) / 2;
                    r = dis(O, q[j]);
                    for (int k = 1; k <= j - 1; ++k){
                        if (dis(O, q[k]) > r){
                            circle(q[i], q[j], q[k]);
                        }
                    }
                }
            }
        }
    }
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
bool check(double lim){
    cnt = 0 ;
    int ans;
    for (int i = 1; i <= n; i = ans + 1)
}
int main(){
    srand(114514);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> p[i].x >> p[i].y;
    }
    work(1, n);
    double L = 0, R = r;
    if (m > 1){
        ci = 50;
        while(ci-- && R - L > eps){
            double mid = (L + R) / 2;
            if (check(mid)) R = mid;
            else L = mid;
        }
    }
    return 0;
}