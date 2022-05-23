#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,cnt;
char map[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m && map[i][j] == '.'){
        map[i][j] = '#';
        for(int k=0; k<4; k++){
            dfs(i+dx[k], j+dy[k]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cnt = 0;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == '.'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}