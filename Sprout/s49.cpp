#include <iostream>
#include <vector>

#define ruby ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
int sz[maxn], root[maxn]{1};

void dfs(int u){
	sz[u] = 1;
	for(int v:adj[u]){
        dfs(v);
		sz[u] += sz[v];
    }
}

int main(){
	ruby
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
        fill(root, root+n+1, 1);
		for(int i=1; i<=n; i++)
			adj[i].clear();
		for(int i=0; i<m; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
            root[v] = 0;
		}
        for(int i=1; i<=n; i++){
            if(root[i]){
                dfs(i);
            }
        }
		int q;
		cin >> q;
		while(q--){
			int x;
			cin >> x;
			cout << sz[x] <<"\n";
		}
	}
}