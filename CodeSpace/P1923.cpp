#include <iostream>
#include <algorithm>

using namespace std;

long long ans = 0, a[5000001];
void qsort(int l, int r, int k) {
	if (l == r) {
		ans = a[l];
		return;
	}
	int  i = l, j = r, mid = (l + r) / 2;
	do {
		while (a[i] < a[mid]) { i++; }
		while (a[j] > a[mid]) { j--; }
		if (i <= j) {
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (k <= j) qsort(l, j, k);
	else if (k >= i) qsort(i, r, k);
	else qsort(j + 1, i - 1, k);
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	qsort(0, n - 1, k);
	cout << ans << endl;
	return 0;
}