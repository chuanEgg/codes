#pragma GCC optimizer("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, c;
        cin >> n >> k >> c;
        vector<int> s(n), dp(n);
        for(auto &i:s)
            cin >> i;
        deque<pair<int,int>> dq;
        dp[0] = s[0];
        dq.push_back({dp[0], 0});
        for(int i=1; i<n; i++){
            dp[i] = s[i];
            while(dq.front().second < i-k)
                dq.pop_front();
            dp[i] = max(-c*i + dq.front().first + s[i], dp[i]);
            while(!dq.empty() && dq.back().first < dp[i]+c*i)
                dq.pop_back();
            dq.push_back({dp[i]+i*c, i});
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        cout << ans <<"\n";
    }
}