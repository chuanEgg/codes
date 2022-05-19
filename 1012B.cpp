#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 4e5+5;
vector<int> adj[maxn];
int vis[maxn]{0};

void dfs(int u, int p){
    for(auto v:adj[u]){
        if(vis[v] || v == p) continue;
        vis[v] = 1;
        dfs(v, u);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i<q; i++){
        int r, c;
        cin >> r >> c;
        c += n;
        adj[r].push_back(c);
        adj[c].push_back(r);
    }
    int ans = 0;
    for(int i=1; i<=n+m; i++){
        if(!vis[i]){
            vis[i] = 1;
            ans++;
            dfs(i, -1);
            // cout << i <<"\n";
        }
    }
    cout << ans-1 <<"\n";
}