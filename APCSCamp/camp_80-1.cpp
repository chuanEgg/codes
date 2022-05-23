#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long temp;
    cin>>n;
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i=0; i<n; i++){
        cin>>temp;
        pq.push(temp);
    }
    temp = 0;
    for(int i=0; i<n-1; i++){
        temp += pq.top();
        pq.pop();
        temp += pq.top();
        pq.pop();
        pq.push(temp);
        ans += temp;
        temp = 0;
    }
    cout<<ans<<"\n";
}