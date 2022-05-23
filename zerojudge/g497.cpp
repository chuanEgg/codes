#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1);
    int ans = 0;
    v[0] = 1;
    for(int i=1; i<=n; i++){
        cin>>v[i];
        ans+=((v[i]-v[i-1]>=0)*3*(v[i]-v[i-1])) + ((v[i]-v[i-1]<0)*-2*(v[i]-v[i-1]));
        //cout<<i<<"\t"<<ans<<"\n";
    }
    cout<<ans<<"\n";
}