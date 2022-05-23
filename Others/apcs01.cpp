#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int ans = 0;
    for(int i=1; i<n-1; i++){
        if(v[i-1] > v[i] && v[i+1] > v[i]){
            ans += v[i];
        }
    }
    cout<<ans<<"\n";
}