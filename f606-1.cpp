#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

using ll = long long;
void solve() {
	ll ans = 1e18, tmp, sum;
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int>(m));
	for (auto& i : v) for (auto& j : i) cin >> j;
	while (k--) {
		tmp = 0;
		vector<int> cnt[m];
		for (int i = 0, x; i < n; i++)
			cin >> x, cnt[x].push_back(i);
		for (int i = 0; i < m; i++) {
			if (cnt[i].empty()) continue;
			for (int j = 0; j < m; j++) {
				sum = 0;
				for (const auto& x : cnt[i]) sum += v[x][j];
				if (i == j) tmp += sum;
				else if (sum > 1000) tmp += 1000 * 3 + (sum - 1000) * 2;
				else tmp += sum * 3;
			}
		}
		ans = min(ans, tmp);
	}
	cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}