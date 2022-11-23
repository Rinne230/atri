#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000001;
int head[maxn];
struct node{
   int to, val, nxt;
}edge[maxn];
int cnt = -1, tot = 0;
void add(int frm, int to, int val){//链式前向星存图
    edge[++cnt].nxt = head[frm];
    edge[cnt].to = to;
    edge[cnt].val = val;
    head[frm] = cnt;    
}
int sum[maxn];
void dfs(int x, int fa){
    for (int i = head[x]; i != -1; i = edge[i].nxt){
        int to = edge[i].to;
        int val = edge[i].val;
        if (to != fa){
            sum[to] = sum[x] ^ val;
            dfs(to, x);
        }
    }
}
struct trie{
    int ch[2];
}t[maxn];
void build(int val, int x){
    for (int i = (1 << 30); i; i >>= 1){//从最高位往下遍历，相当于在树中从上往下走
        bool c = val & i;//如果最高位为1则此时结果为0，说明这一位可以异或，因为最后都与根节点异或
        if (!t[x].ch[c]){//如国这个点没被访问过
            t[x].ch[c] = ++tot;
        }
        x = t[x].ch[c];
    }
}
int query(int val, int x){
    int ans = 0;
    for (int i = (1 << 30); i; i >>= 1){//从最高位往下遍历，相当于在树中从上往下走
        bool c = val & i;//如果最高位为1则此时结果为0，说明这一位可以异或，因为最后都与根节点异或
        if (t[x].ch[!c]){//如果这一位可以异或，就沿着这一条线往下走
            ans += i;
            x = t[x].ch[!c];
        }else x = t[x].ch[c];
    }
    return ans;
}
int main(){
    int n, ans = 0;
    memset(head, -1, sizeof(head));
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i){build(sum[i], 0);}
    for (int i = 1; i <= n; ++i) ans = max(ans, query(sum[i], 0));
    cout << ans << endl;
    return 0;
}