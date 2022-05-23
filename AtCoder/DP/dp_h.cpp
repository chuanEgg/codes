#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char m[1001][1001];
long long dp[1001][1001];
const long long mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=k; j++){
            cin>>m[i][j];
            if(m[i][j] == '.'){
                dp[i][j] = dp[i-1][j]+dp[i][j-1]+dp[i][j];
                dp[i][j] %= mod;
            }else{
                dp[i][j] = 0;
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<dp[n][k]<<"\n";
}