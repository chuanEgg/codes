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
    int n,c;
    cin>>n>>c;
    vector<int> coin(n), dp(c+1);
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int sum = 0; sum <= c; sum++){
            if(sum-coin[i] >=0){
                dp[sum] += dp[sum-coin[i]];
                dp[sum] %= mod;
            }
        }
    }
    // for(int i=0; i<=c; i++) cout<<dp[i]<<" ";
    // cout<<endl;
    cout<<dp[c]<<"\n";
}