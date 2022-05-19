#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5+5;
vector<int> adj[maxn];
int w[maxn], mn[maxn], mx[maxn];

void dfs(int u, int p){
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
        mn[u] = min(mn[u], mn[v]);
        mx[u] = max(mx[u], mx[v]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        cin >> w[i];
        mn[i] = mx[i] = w[i];
    }
    dfs(1, 0);
    // for(int i=1; i<=n; i++){
    //     cout << mx[i] << " "<<mn[i]<<"\n";
    // }
    while(q--){
        int u;
        cin >> u;
        cout << mx[u] - mn[u] <<"\n";
    }
}