#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define ii pair<int, int>
#define mp make_pair

int n, m;
char A[1000][1000];
bool vis[1000][1000];

// previousStep stores the previous direction that we moved in to arrive that this cell
int previousStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";

int main() {
	cin >> n >> m;

	queue<ii> q;
	ii begin, end;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'A') {
				begin = mp(i, j);
			} else if (A[i][j] == 'B') {
				end = mp(i, j);
			}
		}
	}

	q.push(begin);
	vis[begin.first][begin.second] = true;

	while (!q.empty()) {
		ii u = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ii v = mp(u.first + dx[i], u.second + dy[i]);
			if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m) continue;
			if (A[v.first][v.second] == '#') continue;
			if (vis[v.first][v.second]) continue;
			vis[v.first][v.second] = true;
			previousStep[v.first][v.second] = i;
			q.push(v);
		}
	}

	if (vis[end.first][end.second]) {
		cout << "YES" << endl;
		vector<int> steps;
		while (end != begin) {
			int p = previousStep[end.first][end.second];
			steps.push_back(p);
			// undo the previous step to get back to the previous square
			// Notice how we subtract dx/dy, whereas we added dx/dy before
			end = mp(end.first - dx[p], end.second - dy[p]);
		}
		reverse(steps.begin(), steps.end());

		cout << steps.size() << endl;
		for (char c : steps) {
			cout << stepDir[c];
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}