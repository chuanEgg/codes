#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+5;
vector<int> adj[maxn];
vector<int> ans(maxn, -1);
int n;

int bfs(int par){
    int u;
    queue<int> q;
    vector<int> d(n+1, -1);
    d[par] = 0;
    ans[par] = max(ans[par], d[par]);
    q.push(par);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(d[v] == -1){
                q.push(v);
                d[v] = d[u] + 1;
                ans[v] = max(ans[v], d[v]);
            }
        }
    }
    return u;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int d1 = bfs(1);
    int d2 = bfs(d1);
    bfs(d2);
    for(int i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}