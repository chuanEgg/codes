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
        int n,k;
        cin>>n>>k;
        vector<int> s(n);
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            s[i] = (int)pow(10,s[i]);
            //cout<<s[i]<<" ";
        }
        //cout<<"\n";
        int ans = 0;
        int i=0;
        while(k>0 && i<n-1){
            //cout<<k<<"\t"<<s[i]<<"\t"<<ans<<"\n";
            cout<<(s[i+1]-1)/s[i]<<"\t"<<k<<"\n";
            if(((s[i+1]-1)/s[i]) > k){
                ans += (k+1)*s[i];
                k -= k;
            }else{
                ans += (s[i+1]-1)/s[i]*s[i];
                k-=((s[i+1]-1)/s[i]);
                //cout<<k<<"\n";
            }
            i++;
        }
        if(k >= 0){
            ans+=(k+1)*s[min(i+1,n-1)];
        }
        cout<<ans<<"\n";
    }
}