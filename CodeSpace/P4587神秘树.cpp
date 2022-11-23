// P4587神秘树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define inf 1e9
struct seg {
	int v, ls, rs;
}t[maxn << 8];
int rt[maxn << 2], cnt, n, m;
void pushup(int o) {
	t[o].v = t[t[o].ls].v + t[t[o].rs].v;
}
void change(int lsto, int& o, int l, int r, int q, int v) {
	if (!o) o = ++cnt;
	if (l == r) {
		t[o].v += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (q <= mid) {
		t[o].rs = t[lsto].rs;
		t[o].ls = ++cnt;
		t[t[o].ls] = t[t[lsto].ls];
		change(t[lsto].ls, t[o].ls, l, mid, q, v);
	}
	else {
		t[o].ls = t[lsto].ls;
		t[o].rs = ++cnt;
		t[t[o].rs] = t[t[lsto].rs];
		change(t[lsto].rs, t[o].rs, mid + 1, r, q, v);
	}
	pushup(o);
}
int query(int o1, int o2, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) {
		return t[o2].v - t[o1].v;
	}
	int mid = (l + r) >> 1, res = 0;
	if (ql <= mid) res += query(t[o1].ls, t[o2].ls, l, mid, ql, qr);
	if (qr > mid) res += query(t[o1].rs, t[o2].rs, mid + 1, r, ql, qr);
	return res;

}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		change(rt[i - 1], rt[i], 1, inf, tmp, tmp);
	}
	cin >> m;
	while (m--) {
		int ans = 1, l, r, lst = 0;
		cin >> l >> r;
		while (1) {
			int res = query(rt[l - 1], rt[r], 1, inf, lst + 1, ans);
			lst = ans;
			if (res) ans += res;
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
