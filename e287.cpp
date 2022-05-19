#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int maxn = 1e6+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    ans = 0;
    cin>>n>>m;
    vector<vector<int>> v(n+2,vector<int>(m+2,0));
    vector<vector<int>> notWalked(n+2,vector<int>(m+2,0));
    int sx, sy;
    int val = maxn;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>v[i][j];
            notWalked[i][j] = true;
            if(v[i][j] < val){
                sx = i;
                sy = j;
                val = v[i][j];
            }
        }
    }
    queue<pair<int,int>> path;
    path.push(make_pair(sx,sy));
    ans+=val;
    notWalked[sx][sy] = 0;
    while(!path.empty()){
        int x = path.front().first;
        int y = path.front().second;
        path.pop();
        int nx, ny;
        int temp = maxn;
        for(int i=0; i<4; i++){
            if(v[x+dx[i]][y+dy[i]] < temp && notWalked[x+dx[i]][y+dy[i]]){
                temp = v[x+dx[i]][y+dy[i]];
                nx = x+dx[i];
                ny = y+dy[i];
            }
        }
        if(temp == maxn){
            continue;
        }
        //cout<<nx<<"\t"<<ny<<"\n";
        notWalked[nx][ny] = 0;
        path.push(make_pair(nx,ny));
        ans += temp;
    }
    cout<<ans<<"\n";
}