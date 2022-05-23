#include <iostream>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    int s[3];
    while(t--){
        int m = 0, cnt = 0;
        for(int i=0; i<3; i++){
            cin>>s[i];
            if(s[i]>m){
                m=s[i];
                cnt = 1;
            }else if(s[i]==m){
                cnt++;
            }
            
        }
        for(int i=0; i<3; i++){
            if(m-s[i] || cnt>1){
                cout<<m-s[i]+1<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<"\n";
    }
}