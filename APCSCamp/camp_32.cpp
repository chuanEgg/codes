#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<long long,long long> P;

const int maxn = 1e6+1;
P s[maxn];
long long ans = 2e7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    priority_queue<long long> pq;
    for(int i=0; i<n; i++){
        cin>>s[i].first>>s[i].second;
    }
    sort(s,s+n);
    for(int i=0; i<n; i++){
        pq.push(s[i].second);
        while(pq.size()>k){
            pq.pop();
        }
        if(pq.size() == k){
            ans = min(ans, (pq.top()+s[i].first));
        }
    }
    cout<<ans<<"\n";
}