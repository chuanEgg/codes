#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 5e5+5, mod = 1e9+7;
int r[maxn], cnt[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, k, q, mx = 0;
    cin >> n >> k >> q;
    vector<int> s(n), s2(n), sum(n);
    for(auto &i:s){
        cin >> i;
        mx = max(mx, i);
    }

    for(int i=0; i<=mx; i++)
        r[i] = rng()%mod;
    
    for(int i=0; i<n; i++){
        cnt[s[i]]++;
        s2[i] = (cnt[s[i]]%k? r[s[i]] : r[s[i]]*-(k-1));
        sum[i] = (i?sum[i-1]+s2[i] : s2[i]);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int temp = (l-1>=0? sum[r]-sum[l-1]: sum[r]);
        cout << (temp? "0":"1");
    }
    cout <<"\n";
}