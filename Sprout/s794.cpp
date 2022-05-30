#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e5+5, max_try = 15;
vector<int> cnt[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, q;
    cin >> n >> q;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        cnt[s[i]].push_back(i);
    }
    
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 0;
        for(int i=0; i<max_try; i++){
            int poke = s[rng()%(r-l+1)+l];
            int temp = upper_bound(cnt[poke].begin(), cnt[poke].end(), r) - lower_bound(cnt[poke].begin(), cnt[poke].end(), l);
            // cout << temp << "\n";
            if(temp > (r-l+1)/2){
                ans = poke;
                break;
            }
        }
        cout << ans <<"\n";
    }
}