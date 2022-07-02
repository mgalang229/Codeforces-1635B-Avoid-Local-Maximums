#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<bool> visited(n, false);
		for (int i = 1; i < n - 1; i++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				if (visited[i - 1]) {
					continue;
				}
				visited[i + 1] = true;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				if (i - 1 >= 0 && i + 1 < n) {
					a[i] = max(a[i - 1], a[i + 1]);
				} else if (i - 1 >= 0) {
					a[i] = a[i - 1];
				}
				ans++;
			}
		}
		cout << ans << '\n';
		for (int x : a) {
			cout << x << " ";
		}
		cout << '\n';
	}
	return 0;
}
