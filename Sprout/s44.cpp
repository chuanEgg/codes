#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

const int maxn = 1e2+5, INF = 1e8;
int n, m, vis[maxn][maxn];
char s[maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        pair<int,int> start, end;
        map<pair<int,int>, int> dis;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> s[i][j];
                if(s[i][j] == 'K'){
                    start = {i, j};
                }
                dis[{i, j}] = INF;
            }
        }
        memset(vis, 0, sizeof(vis));
        queue<pair<int,int>> q;
        q.push(start);
        dis[start] = 0;
        vis[start.first][start.second] = 1;
        int ans = INF;
        while(!q.empty()){
            pair<int,int> now = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || s[nx][ny] == '#' || vis[nx][ny])
                    continue;
                dis[{nx, ny}] = dis[now]+1;
                q.push({nx, ny});
                vis[nx][ny] = 1;
                if(s[nx][ny] == '@'){
                    ans = dis[{nx, ny}];
                }
            }
            if(ans != INF) break;
        }
        if(ans == INF){
            cout << "= =\"\n";
        }else{
            cout << ans <<"\n";
        }
    }
}