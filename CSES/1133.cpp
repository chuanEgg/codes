#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;
const int maxn = 2e5+5;
vector<int> adj[maxn];

int ans[maxn]{0}, dp[maxn]{0}, n;
void dfs(int u, int p, int dep){
    ans[1] += dep;
    dp[u] = 1;
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v, u, dep+1);
        dp[u] += dp[v];
    }
}
void reroot(int u, int p){
    for(auto v:adj[u]){
        if(v == p) continue;
        ans[v] += ans[u]+n-2*dp[v];
        reroot(v, u);
        //ans[v] -= ans[u]+n-2*dp[v];
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    reroot(1, 0);
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}