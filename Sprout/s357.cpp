#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, r;
    cin >> n >> m >> r;
    vector<pair<int,int>> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i].first >> s[i].second;
        s[i].first *= m;
        s[i].second *= 100;
    }
    m *= 100;
    r *= 100;
    sort(s.begin(), s.end(), greater<pair<int,int>>());
    if(!n || s[0].first < m){
        cout << "-1\n";
        return 0;
    }
    int cur = m, t = 0, i = 0, d = 0;
    priority_queue<int> use;
    while(cur > 0){
        while(i < n && s[i].first >= cur){
            use.push(s[i++].second);
        }
        if(!use.empty()){
            d += use.top();
            use.pop();
        }
        if(r >= d && use.empty()){
            cout << "-1\n";
            return 0;
        }
        cur = min(cur-d+r, m);
        t ++;
    }
    cout << t <<"\n";
}