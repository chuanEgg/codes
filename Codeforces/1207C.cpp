#include <iostream>
#include <cstring>
#define INF 3e18;
using namespace std;
#define int long long
const int maxn = 2e5+1;
char in[maxn];
int n,a,b,s[maxn];
int dp[maxn][2];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>n>>a>>b;
        for(int i=1; i<=n; i++){
            cin>>in[i];
            s[i]=in[i]-'0';
        }
        int ans = a*(n)+b*(n+1);
        dp[1][1]=INF;
        for(int i=2; i<n; i++){
            if(s[i]){
                dp[i][1] = min(dp[i-1][1], dp[i-1][0] + a +b)+b;
                dp[i][0] = INF;
            }else{
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + a);
                dp[i][1] = min(dp[i-1][0] + a + b, dp[i-1][1])+b;
            }
            //cout<<i-1<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
        }
        dp[n][0] =min(dp[n-1][0], dp[n-1][1]+a);
        cout<<dp[n][0]+ans<<"\n";
    }
}