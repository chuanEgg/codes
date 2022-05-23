#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define int long long
int n,k;
vector<int> v;

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int l=-1, r=1e9, m;
    while(l<r-1){
        int m=l+(r-l)/2;
        int cnt=1, pos=v[0];
        for(int i=0; i<n; i++){
            if(v[i]>pos+m){//!包覆
                cnt++;
                pos=v[i];
            }
        }
        if(cnt>k)
            l=m;
        else
            r=m;
    }
    cout<<r<<"\n";
}