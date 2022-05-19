#include <iostream>

using namespace std;

unsigned long long dp[5000001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=1000000007;
    }
    cout<<dp[n]<<"\n";
}