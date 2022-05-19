#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<short,short> a, pair<short,short> b){
    return a.second > b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    short n;
    int m;
    cin >> n >> m;
    vector<pair<short,short>> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i].first >> s[i].second;
    }
    sort(s.begin(), s.end(), cmp);
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += min(m, (int)s[i].first)*s[i].second;
        m -= min(m, (int)s[i].first);
    }
    cout << ans <<"\n";
}