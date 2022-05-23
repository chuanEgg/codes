#include <iostream>
#include <cstring>
 
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
 
long long s[101], sum[101], dp[101][101];
long long DP(int i, int j){
    if(dp[i][j]!=INF) return dp[i][j];
    if(i==j) return dp[i][j] = 0;
    for(int m=i; m<j; m++){
        dp[i][j] = min(dp[i][j], DP(i,m)+DP(m+1,j)+sum[j]-sum[i-1]);
    }
    return dp[i][j];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        sum[0] = 0;
        for(int i=1; i<=n; i++){
            cin>>s[i];
            sum[i] = sum[i-1]+s[i];
        }
        memset(dp,0x3f,sizeof(dp));
        cout<<DP(1,n)<<"\n";
    }
}