#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int ans = 0;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i){
            ans += max(0LL, v[i-1]-v[i]);
            v[i] += max(0LL, v[i-1]-v[i]);
        }
    }
    cout<<ans<<"\n";
}