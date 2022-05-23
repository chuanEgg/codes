#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, temp;
    cin>>n;
    unsigned long long ans=0, temp2=0;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        cin>>temp;
        pq.push(temp);
    }
    while(!pq.empty()){
        temp2+=pq.top();
        ans+=(temp2);
        pq.pop();
    }
    cout<<ans<<"\n";
    return 0;
}