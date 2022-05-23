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
        int x,y;
        cin>>y>>x;
        int res, cnt = 1;
        if(y>=x){
            if(y%2 == 0){
                res = y*y;
                res = res-x+1;
            }else{
                res = (y-1)*(y-1)+1;
                res = res+x-1;
            }
        }else{
            if(x%2 == 1){
                res = x*x;
                res = res-y+1;
            }else{
                res = (x-1)*(x-1)+1;
                res = res+y-1;
            }
            
        }
        cout<<res<<"\n";
    }
}