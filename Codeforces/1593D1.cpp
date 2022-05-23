#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;

int s[41];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, mm = 1e6+1, ans;
        cin>>n;
        memset(s,0,sizeof(s));
        for(int i=0; i<n; i++){
            cin>>s[i];
            mm = min(mm,s[i]);
        }
        //cout<<mm<<"\n";
        for(int i=0; i<n; i++){
            if(s[i]!=mm){
                ans = s[i]-mm;
                break;
            }
            if(i==0){
                ans = -1;
            }
        }
        //cout<<ans<<"\n";
        for(int i=0; i<n; i++){
            if(ans == -1) break;
            if(s[i]!=mm){
                ans = __gcd(ans,(s[i]-mm));
            }
        }
        cout<<ans<<"\n";
    }
}