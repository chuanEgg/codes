#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

const int maxn = 2e5+5;
vector<int> adj[maxn], euler;
int in[maxn], out[maxn];
int s[maxn], bit[maxn];

void dfs(int u, int p){
    euler.push_back(u);
    in[u] = euler.size();
    for(auto v:adj[u]){
        if(v == p){continue;}
        dfs(v,u);
         euler.push_back(u);
    }
    out[u] = euler.size();
}
int query(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= i&(-i);
    }
    return res;
}
void update(int i, int val){
    while(i<maxn){
        bit[i] += val;
        i += i&(-i);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    // for(auto u:euler){
    //     cout<<u<<" ";
    // }cout<<"\n";
    for(int i=1; i<=n; i++){
        // cout<<in[i]<<" "<<out[i]<<"\n";
        update(in[i], s[i]);
        update(out[i]+1, -s[i]);
    }
    while(q--){
        int op;
        cin>>op;
        if(op == 1){
            int i,x;
            cin>>i>>x;
            update(in[i], -s[i]+x);
            update(out[i]+1, s[i]-x);
            s[i] = x;
        }else{
            int i;
            cin>>i;
            cout<<query(in[i])<<"\n";
        }
    }
}