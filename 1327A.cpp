#include <iostream>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k*k <= n && n%2 == k%2){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}