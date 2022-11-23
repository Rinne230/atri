#include <bits/stdc++.h>
using namespace std;
int cost[10001], ans[10001];
int add[3001][3001];
bool f[3000];
int n;
int a, b, c; 
void Dijkstra(){
    for(int i = 1; i < n; i++){
        int maxn = 0x7fffffff;
        for(int j = 1; j <= n; j++)
        if(!f[j] && cost[j] < maxn) 
            b = j, maxn = cost[j];
        f[b]=1;
        for(int j = 1; j <= n; j++)
        if(f[j] && add[b][j]){
            if(cost[b] + cost[j] == cost[add[b][j]])
                ans[add[b][j]] += ans[b] * ans[j];
            if(cost[b] + cost[j] < cost[add[b][j]]) 
                cost[add[b][j]] = cost[b]+cost[j], ans[add[b][j]] = ans[b] * ans[j];
        }
     }
}
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d", &cost[i]), ans[i] = 1;
    while(scanf("%d%d%d", &a ,&b, &c)!=EOF) add[a + 1][b + 1] = add[b + 1][a + 1]=c + 1;   
    Dijkstra();
    printf("%d %d",cost[1], ans[1]); 
    return 0;
}