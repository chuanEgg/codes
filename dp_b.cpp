#include <iostream>
#include <cmath>
#define int long long
using namespace std;

const int maxn = 1e5+1;
int s[maxn];
int dp[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>s[i];
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int m = 1e18;
        for(int j=1; j<=k && (i-j)>=0; j++){
            m = min(m, dp[i-j]+abs(s[i-j]-s[i]));
        }
        dp[i] = m;
    }
    cout<<dp[n-1]<<"\n";
}