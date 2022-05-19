#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
char map[105][105];
int changed[105][105];
void dfs(int i, int j){
    if(changed[i][j] || i<= 0|| i>n || j<=0 || j>m || map[i][j] == '*') return;
    changed[i][j] = 1;
    for(int di=-1; di<=1; di++){
        for(int dj=-1; dj<=1; dj++){
            dfs(i+di, j+dj);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m && (n||m)){
        int ans = 0;
        memset(map,0,sizeof(map));
        memset(changed,0,sizeof(changed));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>map[i][j];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(!changed[i][j] && map[i][j] == '@'){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}