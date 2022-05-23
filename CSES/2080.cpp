#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int maxn = 2e5+5;
vector<int> adj[maxn];
int sz[maxn], vis[maxn]{0}, cnt[maxn]{1};
int n, k, ans;

void dfs_sz(int u, int p){
    sz[u] = 1;
    for(auto v:adj[u]){
        if(v == p || vis[v]) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}
int find_centroid(int u, int p, int root){
    for(auto v:adj[u]){
        if(v == p || vis[v]) continue;
        if(sz[v] >= sz[root]/2)
            return find_centroid(v, u, root);
    }
    return u;
}
void find_ans(int u, int p, int dep){
    if(dep > k) return;
    ans += cnt[k-dep];
    // cout<<u<<"\t"<<dep<<"\t"<<cnt[k-dep]<<"\n";
    for(auto v:adj[u]){
        if(v == p || vis[v]) continue;
        find_ans(v, u, dep+1);
    }
}
void find_dep(int u, int p, int dep){
    if(dep > k) return;
    cnt[dep]++;
    for(auto v:adj[u]){
        if(v == p || vis[v]) continue;
        find_dep(v, u, dep+1);
    }
}
void decompose(int u){
    dfs_sz(u, -1);
    int c = find_centroid(u, -1, u);
    vis[c] = 1;
    for(auto v:adj[c]){
        if(vis[v]) continue;
        find_ans(v, c, 1);
        find_dep(v, c, 1);
    }
    // cout<<"\t\t"<<c<<"\t"<<ans<<"\n";
    fill(cnt+1, cnt+sz[u]+1, 0);
    for(auto v:adj[c]){
        if(vis[v]) continue;
        decompose(v);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    // cnt[0] = 1;
    decompose(1);
    cout<<ans<<"\n";
}