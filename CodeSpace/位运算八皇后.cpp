#include <bits/stdc++.h>
using namespace std;
long sum = 0, upperlim = 1;
int lowbit(int x) {return x & (-x);}
void solve(long row, long ld, long rd){
    if (row != upperlim){
        long pos = upperlim & ~(row | ld | rd);
        while (pos){
            long p = lowbit(pos);
            pos -= p;
            solve(row + p, (ld + p) << 1, (rd + p) >> 1);
        }
    }
    else{
        sum++;
    }
}

int main() {
    int n;
    cin >> n;
    clock_t start = clock();
    upperlim = (upperlim << n) - 1;
    solve(0, 0, 0);
    clock_t end = clock();
    long double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(28) << elapsed_secs << " s" << endl;
    printf("%d\n", sum);

    return 0;
}