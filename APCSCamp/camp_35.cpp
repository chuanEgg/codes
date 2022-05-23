#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,l,x,k;
    unsigned long long ans=0;
    cin>>n>>l;
    pair<int,int> arr[n];
    for(int i=0; i<n; i++){
        cin>>x>>k;
        arr[i]=make_pair(x,k);
    }
    sort(arr,arr+n,cmp);
    set<int> s;
    s.insert(0);
    s.insert(l);
    for(int i=0; i<n; i++){
        s.insert(arr[i].first);
        auto iter=s.lower_bound(arr[i].first);
        if(next(iter)==s.end()){
            ans+=*(iter)-*(prev(iter));
            //cout<<*(iter)<<" "<<*(prev(iter))<<"\n";
        }else if(iter==s.begin()){
            ans+=*(next(iter))-*(iter);
            //cout<<*(next(iter))<<" "<<*(iter)<<"\n";
        }else{
            ans+=*(next(iter))-*(prev(iter));
            //cout<<*(next(iter))<<" "<<*(prev(iter))<<"\n";
        }
        
    }
    cout<<ans<<"\n";
}