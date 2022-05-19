#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn], ans;
int par[maxn], visited[maxn];

void dfs(int u, int p){
    visited[u] = 1;
    // cout<<u<<"\t"<<p<<"\n";
    for(auto v:adj[u]){
        if(v == p) continue;
        // cout<<v<<"\n";
        if(visited[v]){
            // cout<<v<<"\n";
            int cur = u;
            ans.push_back(v);
            while(cur != v){
                ans.push_back(cur);
                cur = par[cur];
            }
            ans.push_back(v);
            cout<<ans.size()<<"\n";
            for(auto i:ans){
                cout<<i<<" ";
            }cout<<"\n";
            exit(0);
        }
        par[v] = u;
        dfs(v, u);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // memset(par, 0, sizeof(par));
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i, i);
        }
    }
    cout<<"IMPOSSIBLE\n";
}