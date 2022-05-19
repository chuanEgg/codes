#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5+5;
vector<int> adj[maxn];
int m[maxn];
int ans = 0;

void dfs(int u, int p){
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v,u);
        if(!m[u] && !m[v]){
            m[u] = m[v] = 1;
            ans++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout<<ans<<"\n";
}