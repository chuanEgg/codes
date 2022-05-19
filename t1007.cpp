#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

int dp[100];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        //前面隨便做
        dp[i] = dp[i-1]*2;
    }
    for(int i=n; i<m; i++){
        for(int j=0; j<=n; j++){
            dp[i+1] += dp[i-j];
        }
    }
    cout<<dp[m]<<"\n";
}