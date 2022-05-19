#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

const int maxn = 1e5+5;
int dsu[maxn], sz[maxn], cnt, mx=1;
set<pair<int,int>> s;

struct S{
    int u, o, v;
};

int find(int u){
    if(dsu[u] == u){
        return u;
    }
    return dsu[u] = find(dsu[u]);
}

void uni(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    dsu[v] = dsu[u];
    sz[u] += sz[v];
    mx = max(mx, sz[u]);
    cnt--;
    // cout << mx <<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    cnt = n;
    iota(dsu, dsu+n+1, 0);
    fill(sz, sz+n+1, 1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        if(u < v) swap(u, v);
        s.insert({u, v});
    }
    vector<S> query(q);
    for(int i=0; i<q; i++){
        cin >> query[i].o;
        if(query[i].o == 1){
            cin >> query[i].u >> query[i].v;
            if(query[i].u < query[i].v) swap(query[i].u, query[i].v);
            s.erase({query[i].u, query[i].v});
            // cout << query[i].u<<" "<< query[i].v<<"\n";
        }
    }
    for(auto p:s){
        int u = p.first, v = p.second;
        // cout << u <<"\t"<<v<<"\n";
        uni(u, v);
    }
    vector<pair<int,int>> ans;
    for(int i=q-1; i>=0; i--){
        if(query[i].o == 1){
            int u = query[i].u, v = query[i].v;
            // if(u < v) swap(u, v);
            // s.insert({u, v});
            uni(u, v);
        }else{
            ans.push_back({cnt, mx});
        }
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i].first <<" "<< ans[i].second<<"\n";
    }
}