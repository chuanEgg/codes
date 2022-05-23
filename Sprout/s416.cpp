#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9+7;

int add(int a, int b){
    int res = a+b;
    return res%mod;
}
int sub(int a, int b){
    int res = a-b;
    if(res < 0)  res += mod;
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<vector<int>> dp(n+2, (vector<int>(k+1, 0)));
    vector<int> sum(n+1, 0);
    sum[a] = 1;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            int d = abs(b-j);
            dp[j][i] = sub(dp[j][i], sum[j]);
            dp[max(j-d+1, 1LL)][i] = add(dp[max(j-d+1, 1LL)][i], sum[j]);
            dp[j+1][i] = add(dp[j+1][i], sum[j]);
            dp[min(j+d, n+1)][i] = sub(dp[min(j+d, n+1)][i], sum[j]);
        }
        // for(int j=1; j<=n; j++){
        //     cout << dp[j][i] <<" ";
        // }cout <<"\n";
        sum[0] = 0;
        for(int j=1; j<=n; j++){
            sum[j] = (sum[j-1]+dp[j][i]) % mod;
            // cout << sum[j] <<' ';
        }
        // cout <<"\n";
    }
    int out = 0;
    for(int i=1; i<=n; i++){
        out += sum[i];
        out %= mod;
    }
    cout << out <<"\n";
}