#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define int long long
using namespace std;

const int maxn = 1e5+5;
const int log = 20;
vector<pair<int,int>> adj[maxn];
int n, m;
int sz[maxn], vis[maxn], par[maxn]{0}, dep2[maxn]{0};
int ans[maxn]{0}, to[maxn]{0}, in[maxn]{0}, cnt[maxn]{0}, lst[maxn];
int dis[log][maxn];

void dfs_sz(int u, int p){
    sz[u] = 1;
    for(auto tmp:adj[u]){
        int v = tmp.first;
        int w = tmp.second;
        if(v == p || vis[v]) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}
int find_centroid(int u, int p, int root){
    for(auto tmp:adj[u]){
        int v = tmp.first;
        int w = tmp.second;
        if(v == p|| vis[v]) continue;
        if(sz[v] > sz[root]/2)
            return find_centroid(v, u, root);
    }
    return u;
}
void cal_dis(int u, int p, int root, int d, int dep = 0){
    dis[d][u] = dep;
    // cout<<"from "<<root<<" to "<<u<<"\ndepth: "<<d<<"\ndis: "<<dis[d][u]<<" (cal_dis)\n\n";
    for(auto tmp:adj[u]){
        int v = tmp.first;
        int w = tmp.second;
        if(v == p || vis[v]) continue;
        cal_dis(v, u, root, d, dep+w);
    }
}
void decompose(int u, int p = 0, int dep = 1){
    dfs_sz(u, -1);
    int c = find_centroid(u, -1, u);
    cal_dis(c, -1, c, dep);
    vis[c] = 1;

    par[c] = p;
    dep2[c] = dep;
    for(auto tmp:adj[c]){
        int v = tmp.first;
        int w = tmp.second;
        if(vis[v]) continue;
        decompose(v, c, dep+1);
    }
}
void update(int u){
    if(in[u]) return;
    in[u] = 1;
    int v = u;
    while(v){
        to[v] += dis[dep2[v]][u];
        lst[v] += dis[dep2[par[v]]][u];
        // cout<<"from "<<v<<" : ";
        // cout<<dis[dep2[v]][u]<<" "<<dis[dep2[par[v]]][u]<<"(update)\n";
        cnt[v]++;
        v = par[v];
    }
}
int get_ans(int u){
    int res = 0;
    int v = u, minus = 0;
    while(v){
        res += (to[v]-lst[v]) + (cnt[v]-minus)*dis[dep2[v]][u];
        minus = cnt[v];
        v = par[v];
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u++; v++;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // fill(par, par+n, 0);
    decompose(1);
    for(int i=0; i<m; i++){
        int op, u;
        cin>>op>>u;
        u++;
        if(op == 1){
            update(u);
            // for(int i=0; i<n; i++){
            //     cout<<i<<" : "<<to[i]<<"\n";
            // }
        }else{
            cout<<get_ans(u)<<"\n";
        }
    }
}