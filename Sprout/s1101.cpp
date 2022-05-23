#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
int color[maxn];

bool dfs(int u, int c){
    color[u] = c;
    for(auto v:adj[u]){
        if(color[v] == c)
            return 0;
        if(color[v] == -1 && !dfs(v, !c))
            return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            adj[i].clear();
            color[i] = -1;
        }
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = 1;
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!dfs(i, 1)){
                    flag = 0;
                    break;
                }
            }
        }
        cout << (flag?"NORMAL.\n":"RAINBOW.\n");
    }
}