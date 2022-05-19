#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

int n,q;
const int maxn = 2e5+5;
int a[maxn], tr[maxn*4], tag[maxn*4];
 
vector<pair<int,int>> adj[maxn];
int sz[maxn], head[maxn], id[maxn], sum[maxn], tmp;
int dep[maxn], heavy[maxn], par[maxn], edge[maxn];

void push(int idx){
    if(tag[idx] != -1){
        tr[idx<<1] = tag[idx];
        tr[idx<<1|1] = tag[idx];
        tag[idx<<1] = tag[idx];
        tag[idx<<1|1] = tag[idx];
        tag[idx] = -1;
    }
}
int combine(int a, int b){
    return a+b;
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
    if(l!=r) push(idx);
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
void update(int ml, int mr, int val, int idx, int l, int r){
    if(l!=r) push(idx);
    if(ml<=l && r<=mr){
        tr[idx] = val;
        tag[idx] = val;
        return;
    }
    int m = (l+r)/2;
    if(ml<=m) update(ml,mr,val,idx*2,l,m);
    if(mr>m) update(ml,mr,val,idx*2+1,m+1,r);
    tr[idx] = combine(tr[idx*2],tr[idx*2+1]);
}
void find_heavy(int u, int p){
    sz[u] = 1;
    par[u] = p;
    dep[u] = dep[p]+1;
    int maxsz = 0, idx = 0;
    for(auto [v,w]:adj[u]){
        if(v == p) continue;
        sum[v] = sum[u]+w;
        edge[v] = w;
        find_heavy(v,u);
        if(sz[v] > maxsz){
            maxsz = sz[v];
            idx = v;
        }
        sz[u] += sz[v];
    }
    heavy[u]= idx;
}
void decompose(int u, int p, int h){
    // cout<<u<<"\n";
    head[u] = h;
    id[u] = ++tmp;
    a[id[u]] = edge[u]; 
    if(heavy[u]){
        decompose(heavy[u], u, h);
    }
    for(auto [v,w]:adj[u]){
        if(v == p || v == heavy[u]) continue;
        decompose(v,u,v);
    }
}
int lca(int u, int v){
    while(head[u]!=head[v]){
        if(dep[head[u]]<dep[head[v]])
            swap(u,v);
        u=par[head[u]];
    }
    if(dep[u]>dep[v])
        swap(u,v);
    return u;
}
int hld_query(int u,int v){
    int res = 0;
    while(head[u]!=head[v]){
        if(dep[head[u]]<dep[head[v]])
            swap(u,v);
        res += query(id[head[u]], id[u], 1, 1, tmp);
        u=par[head[u]];
    }
    if(dep[u] > dep[v])
        swap(u,v);
    if(u == v){
        return res;
    }
    res += (query(id[u]+1, id[v], 1, 1, tmp));
    return res;
}
void hld_update(int u, int v, int val){
    if(dep[u] > dep[v])
        swap(u,v);
    while(head[u]!=head[v]){
        if(dep[head[u]]<dep[head[v]])
            swap(u,v);
        update(id[head[u]], id[u], val, 1, 1, tmp);
        u=par[head[u]];
    }
    if(dep[u] > dep[v])
        swap(u,v);
    update(id[u]+1, id[v], val, 1, 1, tmp);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill(tag,tag+maxn*4,-1);
    cin>>n>>q;
    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    tmp = 0;
    dep[0] = -1;
    find_heavy(1, 0);
    decompose(1,0,1);
    build(1,1,tmp);
    for(int i=0; i<q; i++){
        int u,v;
        cin>>u>>v;
        cout<<hld_query(u ,v)<<"\n";
        hld_update(u ,v, 0);
    }
}