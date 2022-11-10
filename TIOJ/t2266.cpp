#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<int> s(n), r(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        sum += s[i];
    }
    set<pair<int,int>> st;
    for(int i=0; i<n; i++){
        cin >> r[i];
        st.insert({r[i], s[i]});
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<k; i++){
            auto pt = st.upper_bound({i, 0});
            if(pt == st.rend()){
                continue;
            }
            cout << (*pt).first << ' ' << (*pt).second << '\n';
        }
    }
}