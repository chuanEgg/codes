#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
int dfn[maxn], low[maxn], cut[maxn]{0}, t;

void dfs(int u, int p){
    dfn[u] = low[u] = ++t;
    int cnt = 0;
    for(int v:adj[u]){
        if(v == p) continue;
        if(!dfn[v]){
            cnt ++;
            dfs(v, u);
            if(dfn[u] <= low[v]){
                cut[u] = 1;
            }
            low[u] = min(low[v], low[u]);
        }else{
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(!p && cnt < 2){
        cut[u] = 0;
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
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(cut[i]){
            ans ++;
        }
    }
    cout << ans <<"\n";
    for(int i=1; i<=n; i++){
        if(cut[i])
            cout << i <<" ";
    }
}