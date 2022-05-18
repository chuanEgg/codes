#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> s(n);
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            cin >> s[i].first >> s[i].second;
            pq.push({s[i].second, s[i].first});
        }
        int ans = 0, temp = 0;
        while(!pq.empty()){
            temp += pq.top().second;
            ans = max(ans, temp+pq.top().first);
            pq.pop();
        }
        cout << ans <<"\n";
    }
}