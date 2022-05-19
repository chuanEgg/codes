#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int mod = 1e9+7;
const int maxn = 1e5+5;
int s[105];
int dp[105][maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(j-1-s[i] >=0){
                dp[i+1][j] = (dp[i+1][j-1] +dp[i][j] -dp[i][j-1-s[i]] + mod)%mod;
            }else{
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) %mod;
            }
        }
    }
    cout<<dp[n][k]<<"\n";
}