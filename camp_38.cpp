#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
long long ans =0;
vector<int> v, out;

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int need=m-v[i]-v[j];
            ans+=upper_bound(v.begin()+j+1, v.end(), need)-lower_bound(v.begin()+j+1, v.end(), need);
        }
    }
    cout<<ans<<"\n";
}