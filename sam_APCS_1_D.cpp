#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;

const int maxn = 1e6+5;
vector<int> adj[maxn], back[maxn];
int deg[maxn]{0}, dp[maxn][2], val[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // vector<int> val(n);
    // vector<vector<int>> dp(n, vector<int>(2));
    for(int i=1; i<=n; i++){
        cin >> val[i];
        dp[i][0] = dp[i][1] = -1e18;
    }
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        back[v].push_back(u);
        deg[v]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!deg[i])
            q.push(i);
    }
    int ans = -1e18;
    for(int i=1; i<=n; i++){
        if(q.empty()) break;
        int s = q.front();
        q.pop();
        
        if(!back[s].empty()){
            for(auto j:back[s]){
                dp[s][0] = max(dp[s][0], max(dp[j][0], dp[j][1]+val[s]));
                dp[s][1] = max(dp[s][1], max(dp[j][1], dp[j][0]-val[s]));
            }
        }else{
            dp[s][0] = 0;
            dp[s][1] = -val[s];
        }
        ans = max({dp[s][0], dp[s][1], ans});
        // cout << s <<"\t"<<ans<<"\n"<<dp[s][0]<<"\t\t"<<dp[s][1]<<"\n";
        for(auto i:adj[s]){
            deg[i]--;
            if(!deg[i])
                q.push(i);
        }
    }
    cout << ans <<"\n";
}