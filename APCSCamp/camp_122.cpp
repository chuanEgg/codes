#include <iostream>
#include <cstring>

using namespace std;

unsigned long long dp[1001][1001];
int s[1001][1001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    memset(dp, 0, sizeof(dp));
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>s[i][j];
        }
    }
    for(int i=0; i<n; i++){
        if(s[i][0]) break;
        dp[i][0]=1;
    }
    for(int i=0; i<m; i++){
        if(s[0][i]) break;
        dp[0][i]=1;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(!s[i][j])
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
            dp[i][j]%=1000000007;
        }
    }    
    while(q--){
        cin>>n>>m;
        cout<<dp[n][m]<<"\n";
    }
    
}