#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int maxn = 2.5e3+5;
vector<pair<int,int>> adj[maxn];
vector<pair<int,int>> adj_back[maxn];
int dis[maxn], par[maxn];
int vis_1[maxn], vis_n[maxn];

void dfs_1(int u){
    if(vis_1[u]) return;
    vis_1[u] = 1;
    for(auto p:adj[u]){
        dfs_1(p.first);
    }
}
void dfs_n(int u){
    if(vis_n[u]) return;
    vis_n[u] = 1;
    for(auto p:adj_back[u]){
        dfs_n(p.first);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int u,v,w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,-w});
        adj_back[v].push_back({u,-w});
    }
    memset(dis,0x3f,sizeof(dis));
    memset(par,0,sizeof(par));
    memset(vis_1,0,sizeof(vis_1));
    memset(vis_n,0,sizeof(vis_n));
    dfs_1(1); dfs_n(n);
    dis[1] = 0;
    // int temp = 0;
    // vector<int> visited(n+1, 0);
    for(int i=0; i<n; i++){
        for(int j=1; j<n+1; j++){
            for(auto p:adj[j]){
                if(dis[p.first] > dis[j]+p.second){
                    dis[p.first] = dis[j]+p.second;
                    if(i == n-1 && vis_1[p.first] && vis_n[p.first]){
                        cout<<"-1\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<-dis[n]<<"\n";

}