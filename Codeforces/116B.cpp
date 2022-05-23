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
        int n,k;
        cin>>n>>k;
        int temp = 1;
        int ans = 0;
        // if(n == 1){
        //     cout<<"0\n";
        //     continue;
        // }
        n-=1;
        while(n > 0){
            if(temp > k){
                //cout<<n<<"\t"<<ans<<"\n";
                temp = k;
                if(n%k == 0){
                    ans += n/k;
                }else{
                    ans += n/k+1;
                }
                break;
            }
            n-=temp;
            temp *= 2;
            
            //cout<<n<<" "<<temp<<"\n";
            ans++;
        }
        cout<<ans<<"\n";
    }
}