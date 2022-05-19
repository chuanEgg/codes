#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+1;
vector<int> adj[maxn];
int visit[maxn];
int last;
int dfs(int u, int p){
    visit[u] = 1;
    last = u;
    for(auto v:adj[u]){
        if(!visit[v]){
            dfs(v,u);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(visit,0,sizeof(visit));
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    last = -1;
    vector<pair<int,int>> ans;
    for(int i=1; i<=n; i++){
        if(!visit[i]){
            if(last != -1){
                ans.push_back({last,i});
            }
            dfs(i,-1);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto p:ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }
}