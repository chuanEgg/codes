#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin>>n>>c;
    vector<int> coin(n);
    for(int i=0; i<n; i++) cin>>coin[i];
    vector<int> dp(c+1,1e6+5);
    dp[0] = 0;
    for(int i=0; i<=c; i++){
        for(int j=0; j<n; j++){
            if(i-coin[j] >= 0)
                dp[i] = min(dp[i-coin[j]]+1,dp[i]);
        }
    }
    if(dp[c] == 1e6+5){
        dp[c] = -1;
    }
    cout<<dp[c]<<"\n";
}