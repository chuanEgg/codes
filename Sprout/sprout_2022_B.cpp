#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    int ans = 0;
    while(q--){
        int sx, sy, ex, ey, x, y;
        cin>>sx>>sy>>ex>>ey>>x>>y;
        if((((ex==x)||(ey==y)) && ((sx==x)||(sy==y)))||((sx==ex)&&(sy==ey))){
            ans++;
        }
    }
    cout<<ans<<"\n";
}