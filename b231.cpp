#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n; i++){
            int a,b;
            cin>>a>>b;
            pq.push({b,a});
        }
        int now = 0, ans = 0;
        while(!pq.empty()){
            now += pq.top().second;
            ans = max(ans,now+pq.top().first);
            pq.pop();
        }
        cout<<ans<<"\n";
    }
}