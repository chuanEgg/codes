#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

const int maxn = 1e6+5;
using namespace std;

vector<int> adj[maxn];
bool pass[maxn]{0};
void dfs(int u){
    if(pass[u]) return;
    pass[u] = 1;
    for(auto v:adj[u]){
        // cout << v <<"\n";
        dfs(v);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l, q;
    cin>>n>>m>>l>>q;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0; i<l; i++){
        int u;
        cin >> u;
        dfs(u);
    }
    for(int i=0; i<q; i++){
        int u;
        cin >> u;
        cout << (!pass[u]?"YA~~\n":"TUIHUOOOOOO\n");
    }
}