#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

const int maxn = 2e5+5;
int n;
vector<pair<int,int>> adj[maxn];
pair<int,int> res[maxn];
int ans;

int dfs(int u, int p){
    int h1 = 0, h2 = 0;
    for(auto i:adj[u]){
        int v = i.first;
        int w = i.second;
        if(v!=p){
            int h = dfs(v,u)+w;
            if(h > h1){
                h2 = h1;
                h1 = h;
            }else if(h > h2){
                h2 = h;
            }
        }
    }
    //cout<<u<<" "<<h1<<" "<<h2<<"\n";
    //res[u] = make_pair(h1,h2);
    ans = max(ans, h1+h2);
    return h1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ans = 0;
    cin>>n;
    for(int i=1; i<n; i++){
        int u,v,w;
        cin>>u>>v;
        u--; v--;
        w = 1;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(0,-1);
    //cout<<res[0].first+res[0].second<<"\n";
    // res.pop();
    // cout<<res.top()<<"\n";
    cout<<ans<<"\n";
}