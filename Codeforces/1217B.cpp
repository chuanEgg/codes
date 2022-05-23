#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,x,maxd = -2e9, bestd = -2e9;
        cin>>n>>x;
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i].first>>v[i].second;
            maxd=max(maxd, v[i].first);
            bestd=max(bestd, v[i].first-v[i].second);
        }
        int res =1;
        x-=maxd;
        //cout<<x<<"\t"<<bestd<<"\n";
        if(x>0){
            if(bestd<=0) res=-1;
            else res+=((x+bestd-1)/bestd);
        }
        cout<<res<<"\n";
    }
}