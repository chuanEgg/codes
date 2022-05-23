#include <iostream>

using namespace std;

const int max_n=100001;

int s[1001][1001], dp[1001][1001];
int ans=-2000000;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>s[i][j];
        }
    }
    for(int i=n; i>=1; i--){
        for(int j=m; j>=1; j--){
            dp[i][j]=max(dp[i+1][j], dp[i][j+1])+s[i][j];
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<"\n";
}