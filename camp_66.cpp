#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans=0;
    cin>>n;
    int f[n];
    vector<int> l(n);
    for(int i=0; i<n; i++){
        cin>>f[i];
    }
    for(int i=0; i<n; i++){
        cin>>l[i];
    }
    sort(l.begin(), l.end());
    for(int i=0; i<n; i++){
        if(f[i]>=*l.rbegin()) continue;
        auto it=upper_bound(l.begin(), l.end(), f[i]);
        //if(it!=l.end()){
            ans++;
            l.erase(it);
        //}
    }
    cout<<ans<<"\n";
}