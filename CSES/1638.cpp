#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> grid(n+1, vector<int> (n+1,0)); 
    vector<vector<char>> map(n+1, vector<char> (n+1));
    grid[1][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
            if(map[i][j] != '*'){
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
                //cout<<grid[i][j]<<"\n";
                grid[i][j] %= mod;
            }
        }
    }
    cout<<grid[n][n]<<"\n";
}