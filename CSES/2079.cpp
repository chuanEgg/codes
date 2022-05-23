#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5+5;
int sz[maxn], n;
vector<int> adj[maxn];

int dfs_size(int u, int p){
    sz[u] = 1;
    for(auto v:adj[u]){
        if(v == p) continue;
        sz[u] += dfs_size(v,u);
    }
    return sz[u];
}
int find(int u, int p){
    for(auto v:adj[u]){
        if(v == p) continue;
        if(sz[v]>(n/2))
            return find(v,u);
    }
    return u;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_size(1,0);
    cout<<find(1,0)<<"\n";
}