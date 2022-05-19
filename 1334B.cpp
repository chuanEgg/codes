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
    while(t--) {
        int n,x;
        cin>>n>>x;
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        sort(s.begin(), s.end(), greater<>());
        int sum = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            sum += s[i];
            if(sum*1.0 / (i+1) >= x){
                ans = (i+1);
            }else{
                break;
            }
        }
        cout<<ans<<"\n";
    }
}