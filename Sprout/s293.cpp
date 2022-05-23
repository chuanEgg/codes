#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
const int maxn = 1e5+5;
int sz[maxn], n, ans;
vector<int> adj[maxn];
 
int dfs_size(int u, int p){
    sz[u] = 1;
    for(auto v:adj[u]){
        if(v == p) continue;
        sz[u] += dfs_size(v,u);
    }
    return sz[u];
}
void find(int u, int p){
    bool flag = 1;
    for(auto v:adj[u]){
        if(v == p) continue;
        if(sz[v]>(n/2)){
            flag = 0;
            break;
        }
    }
    if(flag && sz[0]-sz[u] <= n/2){
        ans = min(ans, u);
    }
    for(auto v:adj[u]){
        if(v == p) continue;
        find(v, u);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin>>n;
        fill(sz, sz+n, 0);
        ans = maxn;
        for(int i=0; i<n; i++) adj[i].clear();
        for(int i=0; i<n-1; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs_size(0,-1);
        find(0,-1);
        cout<<ans<<"\n";
    }
}