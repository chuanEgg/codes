#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
 
using namespace std;
 
#define int long long
const int maxn = 1e5+5, INF = 1e6;
vector<pair<int,int>> adj[maxn];
int n, e, d, mxw = 0, mnw = 1e9+10, par[maxn]{0}, dis[maxn];

void dfs(int u, int m){
    for(auto p:adj[u]){
        int v = p.first, w = p.second;
        if(w <= m){
            if(dis[v] > dis[u]+1){
                dis[v] = dis[u]+1;
                par[v] = u;
                // cout << m <<"\t"<<v<<"\t"<<dis[v]<<"\n";
                dfs(v, m);
            }
        }
    }
}
bool get_ans(int m){
    fill(par, par+n+1, 0);
    fill(dis, dis+n+1, INF);
    dis[1] = 0;
    dfs(1, m);
    // cout << m <<"\t\t"<< dis[n]<<"\n";
    if(dis[n] <= d){
        return 1;
    }else{
        return 0;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e >> d;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        mxw = max(mxw, w);
        mnw = min(mnw, w);
    }
    int l = mnw, r = 1e9+5;
    while(l<r){
        int m = (l+r)/2;
        // cout << l <<"\t\t\t\t"<<r<<"\n";
        if(get_ans(m)){
            r = m;
        }else{
            l = m+1;
        }
    }
    get_ans(l);
    // cout << l <<"\t";
    if(l > 1e9){
        cout << "-1\n";
        return 0;
    }
    cout << dis[n]<<"\n";
    vector<int> ans;
    int u = n;
    ans.push_back(n);
    while(u != 1){
        ans.push_back(par[u]);
        u = par[u];
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i]<<" ";
    }
    cout << "\n";
}