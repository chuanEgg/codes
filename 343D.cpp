#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 5e5+5;
int n, m;
vector<int> adj[maxn], euler;
int in[maxn], par[maxn]{0}, out[maxn], dep[maxn];
bool tr[maxn<<4], tag[maxn<<4]{0};

void dfs(int u, int p){
    in[u] = euler.size();
    euler.push_back(u);
    for(auto v:adj[u]){
        if(v == p) continue;
        par[v] = u;
        dfs(v, u);
        euler.push_back(u);
    }
    out[u] = euler.size()-1;
}
int combine(int a, int b){
    return a & b;
}
void push(int idx){
    if(tag[idx]){
        tag[2*idx] = tag[idx];
        tag[2*idx+1] = tag[idx];
        tr[idx*2] = tag[idx];
        tr[idx*2+1] = tag[idx];
        tag[idx] = 0;
    }
}
void modify(int ql, int qr, int idx, int l, int r){
    if(l != r) push(idx);
    if(ql <= l && r <= qr){
        tr[idx] = 1;
        tag[idx] = 1;
        return;
    }
    int m = (l+r)/2;
    if(ql <= m)
        modify(ql, qr, idx*2, l, m);
    if(m < qr)
        modify(ql, qr, idx*2+1, m+1, r);
    tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
}
void update(int pos, int idx, int l, int r){
    if(l != r) push(idx);
    if(l == r){
        tr[idx] = 0;
        return;
    }
    int m = (l+r)/2;
    if(pos <= m)
        update(pos, idx*2, l, m);
    else
        update(pos, idx*2+1, m+1, r);
    tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
}
int query(int ql, int qr, int idx, int l, int r){
    if(ql > r || qr < l) return 1;
    if(ql <= l && r <= qr){
        return tr[idx];
    }
    push(idx);
    int m = (l+r)/2;
    int res = 1;
    if(ql <= m)
        res = combine(res, query(ql, qr, idx*2, l, m));
    if(qr > m)
        res = combine(res, query(ql, qr, idx*2+1, m+1, r));
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cin >> m;
    // for(int i = 1; i<=n; i++){
    //     cout<<in[i]<<"\t"<<out[i]<<"\n";
    // }cout<<"\n";
    // for(auto i:euler)
    //     cout<<i<<" ";
    // cout<<"\n";
    n = euler.size();
    while(m --){
        int op, v;
        cin>>op>>v;
        if(op == 1){
            if(!query(in[v], out[v], 1, 0, n-1) && par[v]){
                update(in[par[v]], 1, 0, n-1);
            }
            modify(in[v], out[v], 1, 0, n-1);
        }else if(op == 2){
            update(in[v], 1, 0, n-1);
        }else{
            cout<<query(in[v], out[v], 1, 0, n-1)<<"\n";
        }
    }
}