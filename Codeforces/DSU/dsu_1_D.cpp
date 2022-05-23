#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

const int maxn = 5e4+5;
int dsu[maxn], sz[maxn]{1};
set<pair<int,int>> s;

struct S{
    string o;
    int u, v;
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
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    iota(dsu, dsu+n+1, 0);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        if(u < v) swap(u, v);
        s.insert({u, v});
    }
    vector<S> query(q);
    for(int i=0; i<q; i++){
        cin >> query[i].o >> query[i].u >> query[i].v;
        if(query[i].o == "cut"){
            if(query[i].u < query[i].v) swap(query[i].u, query[i].v);
            s.erase({query[i].u, query[i].v});
        }
    }
    for(auto p:s){
        int u = p.first, v = p.second;
        // cout << u <<"\t"<<v<<"\n";
        uni(u, v);
    }
    vector<int> ans;
    for(int i=q-1; i>=0; i--){
        int u = query[i].u, v = query[i].v;
        if(query[i].o == "cut"){
            if(u < v) swap(u, v);
            s.insert({u, v});
            uni(u, v);
        }else{
            ans.push_back((find(u) == find(v)));
        }
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout << (ans[i]?"YES\n":"NO\n");
    }
}