#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 3005;
int dp[maxn][maxn];
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    int n;
    string s;
    cin>>n>>s;
    //dp[i][j] -> at place i ,and the last digit is j
    dp[1][1] = 1;
    for(int i=2; i<= n; i++){
        if(s[i-2] == '<'){
            dp[i][1] = 0;
            // dp[i][j]
            // = dp[i - 1][1] + ... + dp[i - 1][j - 1];
            // = dp[i][j - 1] + dp[i][j - 1];
            for(int j=2; j<=i; j++){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%mod;
            }
        }else{
            dp[i][i] = 0;
             // dp[i][j]
             // = dp[i - 1][i - 1] + ... + dp[i - 1][j];
             // = dp[i][j + 1] + dp[i - 1][j];
            for(int j=i-1; j>=1; j--){
                dp[i][j] = (dp[i-1][j]+dp[i][j+1])%mod;
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += dp[n][i];
        if(ans >= mod) ans-=mod;
    }
    cout<<ans<<"\n";
}