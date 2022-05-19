#include <iostream>
#include <map>
#include <vector>

#define int long long
using namespace std;

const int maxn = 3e5+10;
int s[maxn], sum[maxn];
vector<int> v;
map<int,vector<int>> mp;

signed main(){
    cin.tie(0);
    int n,ans = -1e18, l, r, fl, fr;
    cin>>n;
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>s[i];
        if(s[i]>0) sum[i] = sum[i-1] + s[i];
        else sum[i] = sum[i-1];
        mp[s[i]].push_back(i);
    }
    for(auto i:mp){
        //cout<<i.second.size()<<"\n";
        if(i.second.size()<2) continue;
        //cout<<"hi\n";
        vector<int> temp = i.second;
        l = *temp.begin();
        r = *temp.rbegin();
        int k = sum[r]-sum[l-1];
        if(i.first<0) k += i.first * 2;
        //cout<<k<<"\n";
        if(k >= ans){
            ans = k;
            fl = l;
            fr = r;
        }else continue;
        v.clear();
        for(int j=l+1; j<r; j++){
            if(s[j]<0) v.push_back(j);
        }
    }
    cout<<ans<<" "<<v.size()+fl-1+n-fr<<"\n";
    for(int i=1; i<fl; i++) cout<<i<<" ";
    for(int i:v) cout<<i<<" ";
    for(int i=fr+1; i<=n; i++) cout<<i<<" ";
    cout<<"\n";
}