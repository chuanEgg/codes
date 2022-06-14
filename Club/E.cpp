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
    int n, m, k, sum = 0;
    cin >> n >> m >> k;
    vector<int> a(n), s;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int temp = 0;
    vector<int> pref;
    for(int i=0; i<((m+sum-1)/sum) * n; i++){
        if(temp + a[i % n] > k){
            s.push_back(temp);
            if(pref.size()){
                pref.push_back(pref.back() + s.back());
            }else{
                pref.push_back(s.back());
            }
            temp = 0;
        }
        temp += a[i % n];
    }
    s.push_back(temp);
    pref.push_back(pref.back() + s.back());
    // for(auto i:s){
    //     cout << i <<" ";
    // }
    cout << lower_bound(pref.begin(), pref.end(), m)-pref.begin() <<"\n";
}