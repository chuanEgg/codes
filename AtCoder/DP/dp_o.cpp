#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>v[i][j];
    vector<int> dp(1<<n);
    dp[0] = 1;
    for(int mask = 0; mask < (1<<n)-1; mask++){
        int k = __builtin_popcount(mask);
        for(int b = 0; b<n; b++){
            if(v[k][b] && !(mask & (1<<b))){
                int m2 = mask ^ (1<<b);
                dp[m2] += dp[mask];
                if(dp[m2] >= mod)
                    dp[m2] -= mod;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
}