#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        if(s[i]) cnt++;
    }
    vector<pair<int,int>> in(m);
    
    for(int i=0; i<m; i++){
        cin >> in[i].first >> in[i].second;
        in[i].first--, in[i].second--;
        if(in[i].first > in[i].second)
            swap(in[i].first, in[i].second);
    }
    if(cnt % 2) cout << "No\n";
    else{
        vector<int> ans;
        for(int i=0; i<m; i++){
            if(s[in[i].first] && s[in[i].second]){
                s[in[i].first] = s[in[i].second] = 0;
                ans.push_back(i);
                in[i].first = in[i].second = -1;
            }
        }
        set<pair<int,int>> st;
        map<pair<int,int>, pair<int,int>> mp;
        for(int i=0; i<m; i++){
            if(in[i].first == -1) continue;
            for(int j=i+1; j<m; j++){
                if(in[i].first == in[j].first){
                    int a = in[i].second, b = in[j].second;
                    if(a > b) swap(a,b);
                    st.insert({a, b});
                    mp[{a,b}] = {i, j};
                }else if(in[i].first == in[j].second){
                    int a = in[i].second, b = in[j].first;
                    if(a > b) swap(a,b);
                    st.insert({a, b});
                    mp[{a,b}] = {i, j};
                }else if(in[i].second == in[j].first){
                    int a = in[i].first, b = in[j].second;
                    if(a > b) swap(a,b);
                    st.insert({a, b});
                    mp[{a,b}] = {i, j};
                }else if(in[i].second == in[j].second){
                    int a = in[i].first, b = in[i].first;
                    if(a > b) swap(a,b);
                    st.insert({a, b});
                    mp[{a,b}] = {i, j};
                }
            }
        }
        for(auto i:st){
            if(s[i.first] && s[i.second]){
                s[i.first] = s[i.second] = 0;
                ans.push_back(mp[i].first);
                ans.push_back(mp[i].second);
            }
        }
        bool flag = 0;
        for(int i=0; i<n; i++){
            if(s[i]) flag = 1;
        }
        if(flag) cout << "No\n";
        else{
            cout << "Yes\n";
            for(int i:ans) cout << i+1 <<' ';
        }
    }
}