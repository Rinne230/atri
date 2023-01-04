
#include <bits/stdc++.h>
using namespace std;
double a[13];
int main(){
    int n = 10;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i)
        for (int j = 1; j <= n - i; ++j)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
double a[13];
int main(){
    int n = 10;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (a[j] < a[i]) swap(a[j], a[i]);
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 10;
    int mx = 0;
    int mid;
    for (int i = 1, tmp; i <= n; ++i){
        cin >> tmp;
        if (mx < tmp){
            mx = tmp;
            mid = i;
        }
    }
    printf("max=%d\n", mx);
    printf("maxindex=%d\n", mid);
}  

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int vis[101], p[101], t, n;
int main(){
    int n = 100;
    for (int i = 2; i <= n; ++i){
	    if(!vis[i]) p[++t] = i;
	    for (int j = 1; j <= t && i*p[j] <= n; ++j){
	        vis[i * p[j]] = 1;
	        if (!(i % p[j])) break;
        }
    }
    for (int i = 1; i <= t; ++i){
        printf("%4d", p[i]);
        if (!(i % 5)) putchar('\n');
    }
    return 0;
}