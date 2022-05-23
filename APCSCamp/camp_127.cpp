#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int s[n], dp[n+2];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    for(int i=0; i<n; i++){
        dp[i+1] = max(dp[i+1], dp[i]+s[i]);
        dp[i+2] = max(s[i]*2+dp[i], dp[i+2]);
    }
    cout<<max(dp[n],dp[n+1])<<"\n";
    //dp[n-1+1]; dp[n-1+2]
}