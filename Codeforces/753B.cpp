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
        int x,n;
        cin>>x>>n;
        int k = n%4;
        int temp = n/4;
        if(!k){
            cout<<x<<"\n";
            continue;
        }
        int d = temp*4+1;
        
        for(int i=0; i<k; i++){
            //cout<<d<<"\n";
            if(x%2==0){
                x-=d;
            }else{
                x+=d;
            }
            d++;
        }
        cout<<x<<"\n";
    }
}