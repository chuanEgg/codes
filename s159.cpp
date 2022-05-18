#pragma GCC optimizer("Ofast")
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> c(n), k(n);
        for(int i=0; i<n; i++)
            cin >> c[i] >> k[i];
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<k[0]; i++){
            dp[0][c[i]*i] = 1;
        }
        for(int i=1; i<n; i++){
            dp[i][0] = 1;
            for(int j=1; j<=m; j++){
                //do the monotone thing
            }
        }
    }
}

//dp[n][m] = dp[n-1][m] || dp[n-1][m-c[i]] || ... || dp[n-1][m-c[i]*k[i]]