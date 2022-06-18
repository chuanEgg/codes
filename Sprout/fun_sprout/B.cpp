#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    vector<int> s(n), sum(n, 0), cnt(n, 0);
    for(int i=0; i<n; i++){
        cin >> s[i];
        if(i) sum[i] = sum[i-1] + s[i];
        else sum[i] = s[i];
    }
    // for(auto i:sum){
    //     cout << i <<'\n';
    // }
    while(m--){
        int idx = rng()%sum[n-1];
        idx ++ ;
        int pos = lower_bound(sum.begin(), sum.end(), idx)-sum.begin();
        // cout << idx << ' ' << pos <<"\t";
        cout << pos+1 <<'\n';
        cnt[pos] ++;
    }
    // for(int i:cnt){
    //     cout << i <<' ';
    // }
    // cout << '\n';
}