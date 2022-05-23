#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
 
const int maxn = 3e5+5;
const int k = 20;
int st[maxn][k];
int log[maxn];
int in[maxn], out[maxn], depth[maxn];
vector<int> adj[maxn], euler;

void build(){
    log[1] = 0;
    for(int i=2; i<=maxn; i++){
        log[i] = log[i/2]+1;
    }
    int n = euler.size();
    for(int i=0; i<n; i++){
        st[i][0] = depth[euler[i]];
        // cout<<depth[euler[i]]<<"\t";
    }//cout<<"\n";
    for(int j=1; j<k; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            if(st[i+(1<<(j-1))][j-1] < st[i][j-1]){
                st[i][j] = st[i+(1<<(j-1))][j-1];
            }else{
                st[i][j] = st[i][j-1];
            }
        }
    }
}
void dfs(int u, int p, int d){
    depth[u] = d+1;
    in[u] = euler.size();
    euler.push_back(u);
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs(v,u,d+1);
        euler.push_back(u);
    }
    out[u] = euler.size();
    //euler.push_back(u);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1,-1);
    // for(auto i:euler){
    //     cout<<i<<" ";
    // }cout<<"\n";
    // for(int i=0; i<n; i++){
    //     cout<<in[i]<<" "<<out[i]<<"\n";
    // }
    // cout<<"\n";
    // for(int i=0; i<n; i++){
    //     cout<<depth[i]<<"\n";
    // }
    // cout<<"\n";
    build();
    while(m--){
        int a,b;
        cin>>a>>b;
        int da = in[a];
        int db = in[b];
        if(da>db) swap(da,db);
        // cout<<a<<" "<<b<<"\n";
        int j = log[db-da+1];
        int res = min(st[da][j], st[db-(1<<j)+1][j]);
        cout<<depth[a]+depth[b]-2*res<<"\n";
    }
}
