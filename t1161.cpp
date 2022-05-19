#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<long long,long long> P;

const int maxn = 1e6+5;
P s[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        long long ans = 1e9;
        cin>>n>>k;
        priority_queue<long long> pq;
        for(int i=0; i<n; i++){
            cin>>s[i].first>>s[i].second;
        }
        sort(s,s+n);
        for(int i=0; i<n; i++){
            pq.push(s[i].second);
            if(pq.size() == k){
                ans = min(ans, (pq.top()+s[i].first));
                pq.pop();
            }
        }
        cout<<ans;
        if(t) cout <<"\n";
    }
    
}