#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

const int maxn = 2e5+5;
int hand[maxn][3], dsu[maxn], ans[maxn], sz[maxn]{1};
set<pair<int,int>> e;
vector<int> child[maxn];

int find(int u){
    if(dsu[u] == u)
        return u;
    return dsu[u] = find(dsu[u]);
}
void uni(int u, int v, int t){
    u = find(u), v = find(v);
    if(u == v) return;
    if(v == find(1)) swap(u, v);
    if(v != find(1) && u == find(1)){
        for(auto i:child[v]){
            ans[i] = t;
        }
    }
    if(sz[u] < sz[v]) swap(u, v);
    while(!child[v].empty()){
        child[u].push_back(child[v].back());
        child[v].pop_back();
    }
    dsu[v] = u;
    sz[u] += sz[v];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> hand[i][1] >> hand[i][2];
        e.insert({i, hand[i][1]});
        e.insert({i, hand[i][2]});
        ans[i] = -1;
    }
    vector<pair<int,int>> q(m+1);
    for(int i=1; i<=m; i++){
        cin >> q[i].first >> q[i].second;
        e.erase({q[i].first, hand[q[i].first][q[i].second]});
    }
    iota(dsu, dsu+n+1, 0);
    for(int i=1; i<=n; i++){
        child[i].push_back(i);
    }
    for(auto p:e){
        int u = p.first, v = p.second;
        if(v == -1) continue;
        uni(u, v, -1);
        // cout << u << "\t" <<v <<"\n";
    }
    for(int i=m; i>=1; i--){
        int p = q[i].first, h = q[i].second;
        uni(p, hand[p][h], i-1);
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] <<"\n";
    }
}
