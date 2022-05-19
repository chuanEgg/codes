#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> s(n), sum(n+1, 0), dp(n+1, 0);
    for(int i=n-1; i>=0; i--)
        cin >> s[i];
    for(int i=0; i<n; i++)
        sum[i+1] = sum[i] + s[i];

    deque<pair<int,int>> dq;
    dq.push_back({0, 0});

    for(int i=1; i<=n; i++){
        while(!dq.empty() && dq.front().second < i-k){
            dq.pop_front();
        }
        dp[i] = dq.front().first;
        // cout << dq.front().first << ' ' <<dp[i] <<' ' << sum[i] <<"\n";
        while(!dq.empty() && dq.back().first < dp[i]+sum[i]){
            dq.pop_back();
        }
        dq.push_back({dp[i]+sum[i], i});
    }
    cout << dp[n] <<'\n';
}

// do the dp reversely
// dp[i] = dp[j] + sum[j]