#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

const int maxn = 3e5+5;
int dsu[maxn], mn[maxn], mx[maxn], sz[maxn];

int find(int u){
    if(dsu[u] == u)
        return u;
    }
    return dsu[u] = find(dsu[u]);
}
void uni(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    dsu[v] = u;
    sz[u] += sz[v];
    mx[u] = max(mx[u], mx[v]);
    mn[u] = min(mn[u], mn[v]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    iota(dsu, dsu+n+1, 0);
    iota(mn, mn+n+1, 0);
    iota(mx, mx+n+1, 0);
    fill(sz, sz+n+1, 1);
    while(m--){
        string o;
        int u, v;
        cin >> o;
        if(o == "union"){
            cin >> u >> v;
            uni(u, v);
        }else{
            cin >> u;
            u = find(u);
            cout << mn[u] <<" "<<mx[u]<<" "<<sz[u]<<"\n";
        }
    }
}