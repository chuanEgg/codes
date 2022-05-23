#include <iostream>
#include <cstring>
#include <vector>
#define int long long
using namespace std;

const int N = 105, W = 1e9+1, V = 1e5+5, INF = 1e18;
int v[N], weight[N];
int n,w,sum;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>w;
    sum = 0;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>v[i];
        sum+=v[i];
    }
    vector<long long> dp(sum+1, INF);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=sum-v[i]; j>=0; j--){
            dp[j+v[i]] = min(dp[j]+weight[i], dp[j+v[i]]);
        }
    }
    int ans = 0;
    for(int i=0; i<=sum; i++){
        if(dp[i]<=w){
            ans = max(ans, i);
        }
    }
    cout<<ans<<"\n";
}