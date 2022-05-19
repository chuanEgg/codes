#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

const int maxn = 3e5+5, max_try = 40;
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
        l--; r--;
        int ans = 1;
        for(int i=0; i<max_try; i++){
            int poke = s[rng()%(r-l+1)+l];
            int in_range = upper_bound(cnt[poke].begin(), cnt[poke].end(), r) - lower_bound(cnt[poke].begin(), cnt[poke].end(), l);
            // cout << in_range <<"\n";
            ans = max(ans, 2*in_range - (r-l+1));
        }
        cout << ans <<"\n";
    }
}