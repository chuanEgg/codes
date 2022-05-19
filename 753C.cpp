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
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        if(n == 1){
            cout<<v[0]<<"\n";
            continue;
        }
        sort(v.begin(), v.end());
        int ans = v[0];
        for(int i=1; i<n; i++){
            ans = max(v[i]-v[i-1], ans);
        }
        cout<<ans<<"\n";
    }
}