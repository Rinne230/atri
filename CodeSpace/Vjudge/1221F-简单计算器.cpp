#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	double a[500], sum;
	while(~scanf("%d", &n)){
		char ch = getchar();
		if(n == 0 && ch=='\n') return 0;
		int num = 1;
		a[num] = n;
        char f;
		while(~scanf("%c%d", &f, &m)){
			if(f == '+') a[++num] = m;
			else if(f == '-') a[++num] = -m;
			else if(f == '*') a[num] *= m;
			else a[num] /= m;
			ch = getchar();
			if(ch=='\n') break;
		}
        sum = 0;
		for(int i = 1; i <= num; ++i) sum += a[i];
		printf("%.2f\n",sum);
	}
	return 0;
} 