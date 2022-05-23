#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[121];
int DP(int i){
    if(dp[i]) return dp[i];
    return dp[i] = dp
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    dp[1] = 1;
    cout<<DP(n)<<"\n";
}