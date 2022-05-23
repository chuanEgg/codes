#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int maxn = 1e5+5, mod = 1000007;
int dp[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , temp;
    fill(dp, dp+maxn, 2);
    temp = dp[2] = 3;
    // cout << temp <<"\n";
    for(int i=4; i<= maxn; i+= 2){
        dp[i] += (dp[i-2] + temp*2);
        dp[i] %= mod;
        temp += dp[i];
        temp %= mod;
    }
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n & 1){
            cout << "0\n";
            continue;
        }  
        cout << dp[n] <<"\n";
    }
}