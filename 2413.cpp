#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int maxn = 1e6+5;
const int mod = 1e9+7;
int dp[maxn][2];
//dp[i][0] -> last two tiles are seperated
//dp[i][1] -> combined

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, m = 0;
    cin>>t;
    vector<int> ans(t);
    for(int i=0; i<t; i++){
        cin>>ans[i];
        m = max(m, ans[i]);
    }
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2; i<=m; i++){
        dp[i][0] = (dp[i-1][0]*4 % mod + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2 % mod) % mod;
    }
    for(auto i:ans){
        cout<<(dp[i][0]+dp[i][1]) % mod<<"\n";
    }
}