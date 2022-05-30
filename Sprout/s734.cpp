#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 2e5+5;
int dsu[maxn];
int find(int u){
    return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}

void uni(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return;
    dsu[u] = v;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
        edges.push_back({w, {v, u}});
    }
    iota(dsu, dsu+n, 0);
    int ans = 0;
    sort(edges.begin(), edges.end());
    for(auto e:edges){
        if(find(e.second.first) != find(e.second.second)){
            ans += e.first;
            uni(e.second.first, e.second.second);
        }
    }
    cout << ans <<"\n";
}