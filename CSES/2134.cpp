#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 2e5+5;
int a[maxn], heavy[maxn], sz[maxn], head[maxn], par[maxn], dep[maxn], id[maxn], tmp;
int n,q;
vector<int> adj[maxn];
int tr[maxn*4];
 
int combine(int a, int b){
    return max(a,b);
}
void build(int idx, int l, int r){
    if(l == r){
        tr[idx] = a[l];
    }
    else{
        int m = (l+r)/2;
        build(idx*2, l, m);
        build(idx*2+1, m+1, r);
        tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
    }
}
int query(int ql, int qr, int idx, int l, int r){
    if(ql <= l && qr >= r){
        return tr[idx];
    }
    int m = (l+r)/2;
    if(qr <= m){
        return query(ql,qr,idx*2,l,m);
    }
    if(ql > m){
        return query(ql,qr,idx*2+1,m+1,r);
    }
    return combine(query(ql,qr,idx*2,l,m), query(ql,qr,idx*2+1,m+1,r));
}
void update(int pos, int val, int idx, int l, int r){
    if(l==r){
        tr[idx] = val;
        return;
    }
    int m = (l+r)/2;
    if(pos <= m) update(pos, val, idx*2, l, m);
    else update(pos, val, idx*2+1, m+1, r);
    tr[idx] = combine(tr[idx*2],tr[idx*2+1]);
}

void find_heavy(int u, int p){
    sz[u] = 1;
    par[u] = p;
    dep[u] = dep[p]+1;
    int maxsz = 0, idx = 0;
    for(auto v:adj[u]){
        if(v == p) continue;
        find_heavy(v,u);
        sz[u] += sz[v];
        if(sz[v] > maxsz){
            maxsz = sz[v];
            idx = v;
        }
    }
    heavy[u]= idx;
}
void decompose(int u, int p, int h){
    // cout<<u<<"\n";
    head[u] = h;
    id[u] = tmp++;
    update(id[u], a[u], 1, 0, n-1);
    if(heavy[u]){
        decompose(heavy[u], u, h);
    }
    for(auto v:adj[u]){
        if(v == p || v == heavy[u]) continue;
        decompose(v,u,v);
    }
}

int hld_query(int u, int v){
    int res = 0;
    while(head[u] != head[v]){
        if(dep[head[u]] < dep[head[v]]) swap(u,v);
        res = max(query(id[head[u]], id[u], 1, 0, n-1), res);
        u = par[head[u]];
    }
    if(dep[u] > dep[v]) swap(u,v);
    res = max(query(id[u], id[v], 1, 0, n-1), res);
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(heavy, 0, sizeof(heavy));
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[0] = -1;
    tmp = 0;
    find_heavy(1,0);
    // for(int i=1; i<=n; i++){
    //     cout<<sz[i]<<" ";
    // }cout<<"\n";
    // for(int i=1; i<=n; i++){
    //     cout<<heavy[i]<<" ";
    // }cout<<"\n";
    decompose(1,0,1);
    // for(int i=1; i<=n; i++){
    //     cout<<head[i]<<" ";
    // }cout<<"\n";
    while(q--){
        int op;
        cin>>op;
        if(op == 1){
            int node, x;
            cin>>node>>x;
            a[node] = x;
            update(id[node], x, 1, 0, n-1);
        }else{
            int l, r;
            cin>>l>>r;
            cout<<hld_query(l,r)<<" ";
        }
    }
    cout<<"\n";
}