#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> k(n), c(m), used(n, 0);
        for(int i=0; i<n; i++){
            cin >> k[i];
        }
        for(int i=0; i<m; i++){
            cin >> c[i];
        }
        sort(k.begin(), k.end(), greater<>());
        int ans = 0, mini = 1e18, l = 0, r = 0;
        for(int i = 0; i < n; i++){
            if(!used[l] && l+1 <= k[i] && l < m){
                ans += c[l];
                used[l] = 1;
                l++;
            }else{
                ans += c[k[i]-1];
            }
        }
        cout << ans <<"\n";
    }
}