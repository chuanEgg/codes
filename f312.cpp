#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a1,a2,b1,b2,c1,c2,n,y1,y2,ans=-1e9;
    cin>>a1>>b1>>c1>>a2>>b2>>c2>>n;
    for(int x=0; x<=n; x++){
        int x2 = n-x;
        y1 = a1*x*x + b1*x + c1;
        y2 = a2*x2*x2+ b2*x2 +c2;
        ans = max(ans, (y1+y2));
    }
    cout<<ans<<"\n";
}