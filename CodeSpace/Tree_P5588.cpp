#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int color[maxn], tot[maxn], cnt[maxn];
int n, edge_num[maxn], sizep[maxn], terminal[maxn];
ll ans1[maxn], ans2[maxn];
vector<int> G[maxn << 1];

void addedge(int u, int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
void dfs(int u, int fa){
	int col = color[u], colcnt = cnt[col];
	int colsonTree = 0, pos = 0;
	sizep[u] = 1;
	for (int i = 0; i < G[u].size(); ++i){
		int v = G[u][i];
		if (v == fa) continue;
		int tmpcol = cnt[col];
		dfs(v, u);
		ans1[u] += 1ll * sizep[u] * sizep[v];
		sizep[u] += sizep[v];
		if (tmpcol != cnt[col]) colsonTree++, pos = v;
	}
	ans1[u] += sizep[u] * (n - sizep[u]);
	if (colcnt || cnt[col] != tot[col] - 1) colsonTree++;//进入当前节点时 cnt[col]已经有值，或者当前节点不为当前颜色的最后一个节点，那么也要使colsonTree++
	cnt[col]++;
	if (colsonTree == 1){
		if (!edge_num[col]) terminal[col] = u;
		else{
			int p = pos ? n - sizep[pos] : sizep[u];
			ans2[col] = 1ll * sizep[terminal[col]] * p;
		}
		edge_num[col]++;
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> color[i];
		tot[color[i]]++;
		terminal[color[i]] = i;
	}
	for (int i = 1, u, v; i < n; ++i){
		cin >> u >> v;
		addedge(u, v);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i){
		if (tot[i] == 0) cout << (1ll * (n * (n - 1) >> 1)) << endl;
		else if (tot[i] == 1) cout << ans1[terminal[i]] << endl;
		else if (edge_num[i] == 2) cout << ans2[i] << endl;
		else cout << 0 << endl;
	}
	return 0;
}