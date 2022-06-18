#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, cnt = 0, mx = 0;
    cin >> n >> m >> q;
    vector<vector<int>> s(n, vector<int>(m));
    vector<vector<int>> res(n, vector<int>(m, 1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> s[i][j];
            if(j)
                if(s[i][j-1] == s[i][j]){
                    mx ++;
                    cnt = max(mx, cnt);
                }else mx = 0;
        }
    }
    for(int t=0; t<=cnt/2; t++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool flag = 1;
                for(int k=0; k<8; k++){
                    int ni = i+dx[k], nj = j+dy[k];
                    if(ni >= n || ni < 0 || nj >= m || nj < 0){
                        flag = 0;
                        break;
                    }
                    if(s[ni][nj] != s[i][j] || res[ni][nj] < res[i][j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    // cout << i <<' '<<j<<'\n';
                    res[i][j] += 2;
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++)
    //         cout << res[i][j] <<' ';
    //     cout << '\n';
    // }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << res[x][y] <<'\n';
    }
}