#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 105, maxm = 2e4+5;
int c[maxn], k[maxn], dp[maxn][maxm];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        memset(dp, 0 , sizeof(dp));
        for(int i=0; i<n; i++)
            cin >> c[i] >> k[i];
        for(int i=0; i<= k[0] && c[0]*i <= m; i++)
            dp[0][c[0]*i] = 1;
        
        for(int i=1; i<n; i++){
            dp[i][0] = 1;
            vector<pair<int,int>> bucket(c[i], {0, 0});
            bucket[0] = {1, 0};
            for(int j=1; j<=m; j++){
                if(bucket[j % c[i]].second < j - c[i]*k[i])
                    bucket[j % c[i]].first = 0;
                dp[i][j] |= (bucket[j % c[i]].first || dp[i-1][j]);
                if(dp[i-1][j])
                    bucket[j % c[i]] = {1, j};
            }
            // for(int j=0; j<m; j++){
            //     cout << j <<" : ";
            //     cout << dp[i][j] <<"\n";
            // }
            // cout <<"\n";
        }
        cout << (dp[n-1][m]?"Yes":"No") <<'\n';
    }
}

//dp[n][m] = dp[n-1][m] || dp[n-1][m-c[i]] || ... || dp[n-1][m-c[i]*k[i]]