#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first*b.second < a.second*b.first;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first;
    }
    for(int i=0; i<n; i++){
        cin>>v[i].second;
    }
    sort(v.begin(), v.end(), cmp);
    int weight = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        ans+=(weight*v[i].second);
        weight+=v[i].first;
    }
    cout<<ans<<"\n";
}