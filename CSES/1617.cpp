#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int ans = 1;
    cin>>n;
    for(int i=0; i<n; i++){
        ans*=2;
        if(ans >= mod)
            ans -= mod;
    }
    cout<<ans<<"\n";
}