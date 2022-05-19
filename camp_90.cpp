#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    char mp[n+2][m+2];
    int d[n+2][m+2];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>mp[i][j];
            d[i][j]=-1;
        }
    }
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    queue<pair<int,int>> q;
    q.push(make_pair(s,t));
    d[s][t]=0;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];
            if(mp[nx][ny]=='.'&&d[nx][ny]==-1){
                q.push(make_pair(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
}