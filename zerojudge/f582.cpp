#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e3+5;
vector<int> adj[maxn];
string name[maxn];

int res;
void dfs(int u, int p){
    for(int i=0; i<name[u].length(); i++){
        if(name[u][i] != name[p][i]){
            res++;
        }
    }
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v,u);
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int u, v;
        string s;
        cin>>u>>v;
        cin>>s;
        name[u] = s;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    res = 0;
    dfs(1, 1);
    cout<<res<<"\n";
}