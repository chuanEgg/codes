#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 2e5+5;
int n;
vector<int> adj[maxn];
int dp[maxn];
int point[maxn];
int ans;

int build(int u, int p){ // 以下節點數
    point[u] = 1;
    for(auto v:adj[u]){
        if(v!=p){
            point[u] += build(v, u);
        }
    }
    return point[u];
}
int DP(int u, int p){ // 累計分數和
    dp[u] = point[u];
    for(auto v:adj[u]){
        if(v!=p){
            dp[u] += DP(v, u);
        }
    }
    return dp[u];
}
void solve(int u, int p){
    ans = max(ans, dp[u]);
    for(auto v:adj[u]){
        if(v!=p){
            dp[u] -= dp[v]+point[v];
            point[u] -= point[v];
            point[v] += point[u];
            dp[v] += point[u];
            dp[v] += dp[u];
            solve(v,u);
            dp[v] -= dp[u];
            dp[v] -= point[u];
            point[v] -= point[u];
            point[u] += point[v];
            dp[u] += dp[v]+point[v];
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ans = 0;
    for(int i=1; i<n; i++){
        int f,t;
        cin>>f>>t;
        f--; t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    build(0,-1);
    DP(0,-1);
    // for(int i=0; i<n; i++){
    //     cout<<dp[i]<<"\n";
    // }
    solve(0,-1);
    // for(int i=0; i<n; i++){
    //     cout<<point[i]<<"\n";
    // }
    cout<<ans<<"\n";
}