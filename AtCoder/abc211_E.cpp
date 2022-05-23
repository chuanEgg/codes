#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int ans = 0, n, k;
set<vector<string>> used;
vector<string> s;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool legal(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n);
}

void dfs(int cur){
    if(used.count(s)){
        return;
    }
    used.insert(s);
    if(cur == 0){
        ans++;
        return;
    }
    vector<pair<int,int>> paint;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(s[i][j] == '.'){
                bool flag = 0;
                for(int k=0; k<4; k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(legal(nx, ny) && s[nx][ny] == '@')
                        flag = 1;
                }
                if(flag)
                    paint.push_back({i, j});
            }
        }
    }
    for(auto p:paint){
        s[p.first][p.second] = '@';
        dfs(cur-1);
        s[p.first][p.second] = '.';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    s.resize(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(s[i][j] == '.'){
                s[i][j] = '@';
                dfs(k-1);
                s[i][j] = '.';
            }
        }
    }
    // dfs(k);
    cout << ans <<"\n";
}