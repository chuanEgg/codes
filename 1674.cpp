#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5+5;
vector<int> adj[maxn];
int sz[maxn];

int dfs(int u){
    if(sz[u]) return sz[u];
    for(auto v:adj[u]){
        sz[u] += dfs(v)+1;
    }
    //cout<<u<<" \t"<<sz[u]<<"\n";
    return sz[u];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill(sz, sz+maxn, 0);
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int p;
        cin>>p;
        p--;
        adj[p].push_back(i);
        sz[p] = 0;
    }
    for(int i=0; i<n; i++){
        cout<<dfs(i)<<" ";
    }
}