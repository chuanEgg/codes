#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
int n, sz[maxn], vis[maxn];
int ans[maxn];

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
        if(sz[v] >= sz[root]/2){
            return find_centroid(v, u, root);
        }
    }
    return u;
}
void decompose(int u, int rank){
    dfs_sz(u, -1);
    int c = find_centroid(u, -1, u);
    vis[c] = 1;
    ans[c] = rank;
    for(auto v:adj[c]){
        if(vis[v]) continue;
        decompose(v, ans[c]+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    decompose(1, 0);
    for(int i=1; i<=n; i++){
        cout<<(char)(ans[i]+'A')<<" ";
    }
}