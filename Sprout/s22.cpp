#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        stack<int> s;
        map<int,int> mp;
        int ans = 0;
        for(int i=0; i<n; i++){
            int k, val=0; cin >> k;
            if(!s.empty()){
                while(!s.empty() && s.top() < k){
                    val++;
                    mp[s.top()]--;
                    s.pop();
                }
                // val = max(val+mp[k], s.size());
                ans+=val+mp[k]+(!s.empty() && mp[k] != s.size());
            }
            // cout << k <<"\t"<<val<<"\t"<<mp[k]<<"\t"<<(!s.empty())<<"\n";
            mp[k]++;
            s.push(k);
        }
        cout << ans <<"\n";
    }
}