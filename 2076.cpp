#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
vector<pair<int,int>> bridge;
int dfn[maxn], low[maxn], t;

void dfs(int u, int p){
    dfn[u] = low[u] = ++t;
    for(auto v:adj[u]){
        if(v == p) continue;
        if(!dfn[v]){
            dfs(v, u);
            if(dfn[u] < low[v])
                bridge.push_back({u, v});
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], low[v]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << bridge.size() <<"\n";
    for(auto p:bridge){
        cout << p.first <<" " <<p.second <<"\n";
    }
}