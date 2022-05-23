#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;
const int mod = 1e9+7;
int dp[maxn][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a;
    cin >> n >> m;
    cin >> a;
    if (a == 0){
        for (int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    }
    else dp[0][a] = 1;
    for (int i = 1; i < n; i++){
        cin >> a;
        if (a){
            dp[i][a] += dp[i-1][a-1];
            dp[i][a] %= mod;
            dp[i][a] += dp[i-1][a];
            dp[i][a] %= mod;
            dp[i][a] += dp[i-1][a+1];
            dp[i][a] %= mod;
        }
        else{
            for (int a = 1; a <= m; a++){
                dp[i][a] += dp[i-1][a-1];
                dp[i][a] %= mod;
                dp[i][a] += dp[i-1][a];
                dp[i][a] %= mod;
                dp[i][a] += dp[i-1][a+1];
                dp[i][a] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++){
        ans += dp[n-1][i];
        ans %= mod;
    }
    cout << ans << "\n";
}