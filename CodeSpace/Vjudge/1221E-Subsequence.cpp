#include <bits/stdc++.h>
using namespace std;
int a[100010];
inline int read(){
    char ch = getchar(); int x = 0, s = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return s * x;
}
int main(){
	int n, ans, i, l, r, temp;
	while(cin >> n >> l >> r){
        deque<int> mn;
        deque<int> mx;
		ans = temp = 0;
		for(int i = 1; i <= n; i++){
			a[i] = read();
			while(!mx.empty() && a[i] >= a[mx.back()]) mx.pop_back();
			mx.push_back(i);
			while(!mn.empty() && a[i] <= a[mn.back()]) mn.pop_back();
			mn.push_back(i);
			while(!mx.empty() && !mn.empty() && a[mx.front()] - a[mn.front()] > r)
			    if(mx.front() < mn.front()) temp = mx.front(), mx.pop_front();
			    else temp = mn.front(), mn.pop_front();
   			if(!mx.empty() && !mn.empty() && a[mx.front()] - a[mn.front()] >= l) ans = max(ans,i - temp);
		}
	    cout << ans << endl;
	}
	return 0;
}
