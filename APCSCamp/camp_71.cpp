#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> s[500001];

bool cmp(pair<int,int> i, pair<int,int> j){
    return i.second<j.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int l,r;
    for(int i=0; i<n; i++){
        cin>>l>>r;
        s[i]={l,r};
    }    
    sort(s, s+n, cmp);
    int i=0, ans=0;
    r=s[i++].second;
    ans++;
    while(i<n){
        if(s[i].first>=r){
            r=s[i].second;
            ans++;
        }
        i++;
    }
    cout<<ans<<"\n";
}