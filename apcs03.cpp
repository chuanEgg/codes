#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+5);
    int m = 0, pos;
    for(int i = 0; i<n; i++){
        cin>>v[i];
        if(v[i] > m){
            pos = i;
            m = v[i];
        }
    }
    //vector<int> used(n+5,0);
    int cnt = 1, ans = 0;
    int l = pos-1;
    int r = pos+1;
    if(l < 0){
        l = n-1;
    }
    if(r >= n){
        r = 0;
    }
    while(cnt < n){
        //cout<<m<<"\t";
        if(v[l] > v[r]){
            m+=v[l];
            //used[l] = 1;
            ans += m;
            l--;
            if(l < 0){
                l=n-1;
            }
        }else{
            m+=v[r];
            //used[r] = 1;
            ans+=m;
            r++;
            if(r>=n){
                r=0;
            }
        }
        //cout<<m<<"\n";
        cnt++;
    }
    cout<<ans<<"\n";
}