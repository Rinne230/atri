#include<bits/stdc++.h>
using namespace std;
int H[10005];
int main(){
	register int i, l, r, h;
	while(scanf("%d%d%d", &l, &h, &r) != EOF) 
		for(i = l; i < r; ++i) H[i] = max(H[i], h); 
	for(i = 1, h = 0; i < 1e4; ++i)
		if(h != H[i]){
			h = H[i];
            printf("%d %d ",i, H[i]);
        }
	return 0;
}