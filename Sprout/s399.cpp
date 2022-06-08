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
    int n, ans = 0;
    cin >> n;
    vector<pair<int,int>> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i].first >> s[i].second;
    }
    map<int,int> mp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x = s[i].first-s[j].first;
            int y = s[i].second-s[j].second;
            int dis = x*x + y*y;
            // cout << i << ' '<<j<<" " << dis<<"\n";
            mp[dis]+=1;
        }
    }
    for(auto i:mp){
        if(i.second > 1)
            ans += (i.second)*(i.second-1)/2;
    }
    cout << ans <<'\n';
}