#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 2e5+5;
vector<int> adj[maxn], euler;
int in[3*maxn], out[3*maxn], value[maxn];
int bit[3*maxn];

int query(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= i&(-i);
    }
    return res;
}
void update(int i, int val){
    while(i<2*maxn){
        bit[i] += val;
        i += i&(-i);
    }
}
void dfs(int u, int p){
    in[u] = euler.size()+1;
    update(in[u], value[u]);
    euler.push_back(u);
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v,u);
        //euler.push_back(u);
    }
    out[u] = euler.size()+1;
    //cout<<u<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>value[i];
    }
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int s,x;
            cin>>s>>x;
            update(in[s], -value[s]);
            value[s] = x;
            update(in[s], value[s]);

        }else{
            int s;
            cin>>s;
            cout<<query(out[s]-1)-query(in[s]-1)<<"\n";
        }
    }
}