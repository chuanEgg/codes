#include <iostream>
#include <queue>

using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<m; i++){
        pq.push(0);
    }
    int temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        int temp2=pq.top()+temp;
        ans=max(ans, temp2);
        pq.pop();
        pq.push(temp2);
    }
    cout<<ans<<"\n";
}