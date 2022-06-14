#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn], par[maxn];
int w[maxn], deg[maxn]{0}, dp[maxn]{0}, vis[maxn]{0};

int dfs(int u){
    int res = 1;
    if(vis[u])
        return 0;
    vis[u] = 1;
    for(int v:par[u]){
        res += dfs(v);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        deg[v] ++;
    }
    queue<int> q;
    for(int i=0; i<n; i++){
        if(deg[i] == 0){
            q.push(i);
            dp[i] = w[i];
        }
    }
    int temp = 0;
    vector<int> back;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(!adj[u].size() && dp[u] >= temp){
            if(temp < dp[u])
                back.clear();
            temp = dp[u];
            back.push_back(u);
            // cout << u <<" "<<dp[u] <<"\n";
        }
        for(int v:adj[u]){
            deg[v] --;
            if(dp[v] <= dp[u]+w[v]){
                if(dp[v] < dp[u]+w[v])
                    par[v].clear();
                dp[v] = dp[u]+w[v];
                par[v].push_back(u);
            }
            if(deg[v] == 0)
                q.push(v);
        }
    }
    int ans = 0;
    for(int u:back){
        // cout << u <<"\n";
        ans += dfs(u);
    }
    cout << ans <<"\n";
}