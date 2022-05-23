#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5, K = 20;

vector<pair<int,int>> adj[N];
int visited[N], sz[N], par[N], cnt[N], sum[N], sub[N], used[N], dep2[N];
int dis[K][N];

void dfs_sz(int u, int p){
    sz[u] = 1;
    for(auto [v,w] : adj[u]){
        if(visited[v]||v==p) continue;
        dfs_sz(v,u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int p, int rt){
    for(auto [v,w] : adj[u]){
        if(visited[v]||v==p) continue;
        if(sz[v] > sz[rt]/2) return centroid(v,u,rt);
    }
    return u;
}

void dfs2(int u, int p, int c, int d, int dep = 0){
    dis[d][u] = dep;
    for(auto [v,w] : adj[u]){
        if(visited[v]||v==p) continue;
        dfs2(v,u,c,d,dep+w);
    }
}

void decompose(int u, int dep = 1, int p = 0){
    dfs_sz(u,-1);
    int c = centroid(u,-1,u);

    dfs2(c,-1,c,dep);

    visited[c] = 1;
    par[c] = p;
    dep2[c] = dep;

    for(auto [v,w] : adj[c]){
        if(visited[v]) continue;
        decompose(v,dep+1,c);
    }
}

void add(int u){
    for(int x = u; x; x = par[x]){
        sum[x] += dis[dep2[x]][u];
        sub[x] += dis[dep2[par[x]]][u];
        cout<<sum[x]<<" "<<sub[x]<<"(update)\n";

        cnt[x]++;
    }
}

int query(int u){
    int ans = 0, now = 0;
    for(int x = u; x; x = par[x]){
        ans += sum[x] - sub[x] + (cnt[x] - now) * dis[dep2[x]][u];
        now = cnt[x];
    }
    return ans;
}

signed main(){
    fastio
    int n,q;
    cin >> n >> q;
    for(int i = 0;i < n-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u++,v++;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    decompose(1);

    while(q--){
        int op, u;
        cin >> op >> u;
        u++;
        if(op==1){
            if(!used[u]) add(u), used[u] = 1;
        }else{
            cout << query(u) << "\n";
        }
    }
}