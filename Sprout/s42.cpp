#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e3+5;
char map[maxn][maxn];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || map[i][j]=='#')
        return;
    map[i][j] = '#';
    for(int k=0; k<4; k++){
        dfs(i+dx[k], j+dy[k]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> map[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == '.'){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans <<"\n";
    }
}