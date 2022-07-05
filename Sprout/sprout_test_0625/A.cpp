#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> x(n), y(n), a(m), b(m), c(m), arrow(m), dp(c+1);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i] >> c[i];

    }
    for(int j=0; j<=c; j++){
        for(int i=0; i<n+m; i++){
            if(i >= n){
                dp[j] = max(dp[j], dp[j-(a[i]+b[i])+c[i]]);
            }else{
                dp[j] = max(dp[j], dp[j-x[i]]+y[i]);
            }
            dp[j] %= 
        }
    }
    cout << dp[c] << '\n';
}