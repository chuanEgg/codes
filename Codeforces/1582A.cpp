#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,ans = 0;
        cin>>a>>b>>c;
        c%=2;
        if(c){
            if(b>0){
                b--;
                ans = -1;
            }else{
                ans = 3;
            }
        }
        b%=2;
        ans += 2*b;
        //cout<<ans<<"\n";
        if(ans > a){
            ans -= a;
            cout<<ans<<"\n";
            continue;
        }
        ans=(a-ans);
        ans%=2;
        cout<<ans<<"\n";
        
    }
}