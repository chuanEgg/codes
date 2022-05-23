#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define int long long
using namespace std;

const int maxn = 1e5+5;
const int inf = 1e18;
vector<int> adj[maxn];
int n, m;
int sz[maxn], vis[maxn], par[maxn], to[maxn];
map<int,int> dis[maxn];

void dfs_sz(int u, int p){
    sz[u] = 1;
    for(auto v:adj[u]){
        if(v == p || vis[v]) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}
int find_centroid(int u, int p, int root){
    // cout<<"\nroot: "<<root<<"\nsize of root: "<<sz[root]<<"\ncur at: "<<u<<"\n";
    for(auto v:adj[u]){
        if(v == p || vis[v]) continue;
        // cout<<"size of "<<v<<": "<<sz[v]<<"\n";
        if(sz[v] > sz[root]/2)
            return find_centroid(v, u, root);
    }
    // cout<<"find centroid: "<<u<<", when root is "<<root<<"\n";
    return u;
}
void cal_dis(int u, int p, int root, int dep){
    dis[root][u] = dep;
    dis[u][root] = dep;
    // cout<<root<<" to "<<u<<" : "<<dis[root][u]<<" (cal_dis)\n";
    for(auto v:adj[u]){
        if(v == p || vis[v]) continue;
        cal_dis(v, u, root, dep+1);
    }
}
void decompose(int u, int p){
    dfs_sz(u, -1);
    int c = find_centroid(u, -1, u);
    // cout<<"\t\t"<<c<<"\n";
    vis[c] = 1;
    if(p != -1)
        par[c] = p;
    cal_dis(c, p, c, 0);
    for(auto v:adj[c]){
        if(vis[v]) continue;
        decompose(v, c);
    }
}
void update(int u){
    int v = u;
    while(v != -1){
        // cout<<u<<" to "<<v<<" : "<<dis[u][v]<<"\n";
        to[v] = min(dis[u][v], to[v]);
        v = par[v];
    }
}
void solve(int u){
    int res = inf;
    int v = u;
    while(v != -1){
        res = min(res, dis[v][u] + to[v]);
        v = par[v];
    }
    cout<<res<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(par, par+n+1, -1);
    fill(to, to+n+1, inf);
    decompose(1, -1);
    update(1);
    for(int i=0; i<m; i++){
        int op, u;
        cin>>op>>u;
        if(op == 1){
            update(u);
        }else{
            solve(u);
        }
    }
}