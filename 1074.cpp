#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    double sum = 0;
    for(int i=0; i<n; i++){
        cin>>v[i];    
    }
    sort(v.begin(), v.end());
    int mid = v[n/2];
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += abs(v[i]-mid);
    }
    cout<<ans<<"\n";
}