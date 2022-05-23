#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++){
            cin>>a[i]>>b[i];
        }
        int ans = 0;
        int m = 1e18;
        for(int i=0; i<n; i++){
            int ni = (i+1)%n;
            int val = min(a[ni], b[i]);
            ans += a[ni] - val;
            m = min(m, val);
        }
        ans += m;
        cout<<ans<<"\n";
    }
}