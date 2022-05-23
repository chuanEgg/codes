#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define int long long

const int maxw = 1005, maxk = 105;
int dp[maxw][maxk];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k, ans = 0;
        cin >> n >> m >> k;
        vector<int> w(n), v(n);
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++){
            cin >> w[i] >> v[i];
        }
        for(int i=0; i<n; i++){
            for(int j = m; j>=0; j--){
                for(int l=1; l<=k; l++){
                    if(j >= w[i]){
                        dp[j][l] = max(dp[j-w[i]][l-1]+v[i], dp[j][l]);
                        ans = max(ans, dp[j][l]);
                    }
                }
            }
        }
        cout << ans <<"\n";
    }
}