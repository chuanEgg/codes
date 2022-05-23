#include <iostream>
#include <vector>
#include <cstring>
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
        vector<int> s(n+1);
        int m = 0;
        int ans = 0;
        int sz = 1;
        for(int i=1; i<=n; i++){
            cin>>s[i];
            if(s[i] > sz){
                sz = s[i];
                ans = max(ans, sz-i);
            }
        }
        cout<<ans<<"\n";
        
    }
}