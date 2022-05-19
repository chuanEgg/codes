#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> s(n);
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0; i<n; i++){
            cin >> s[i];
            pq.push(s[i]);
        }
        long long ans = 0;
        while(pq.size() >= 2){
            long long temp1 = pq.top(); pq.pop();
            long long temp2 = pq.top(); pq.pop();
            ans += (temp1 + temp2);
            pq.push(temp1+temp2);
        }
        cout << ans <<"\n";
    }
}