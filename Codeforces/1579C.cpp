#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char map[20][20];
int killed[20][20]{1};
int cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> status(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                if (s[j] == '*')
                    status[i][j] = 1;
        }
        for (int i = n - 1; i > -1; i--) {
            for (int j = 0; j < m; j++) {
                if (status[i][j] == 0)
                    continue;
                int len = 0;
                while (j > len && j + len + 1 < m && i > len) {
                    if (status[i - len - 1][j - len - 1] == 0 || status[i - len - 1][j + len + 1] == 0)
                        break;
                    len++;
                }
                if (len >= k) {
                    for (int d = 0; d <= len; d++) {
                        status[i - d][j - d] = 2;
                        status[i - d][j + d] = 2;
                    }
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (status[i][j] == 1)
                    ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }
}