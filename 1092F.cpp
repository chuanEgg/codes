#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

const int maxn = 2e5+5;
int n, ans, res;
int dis[maxn], dp[maxn], a[maxn] , score[maxn];
vector<int> adj[maxn];

// void calcdis(int u, int p){
//     if(p>=0)
//         dis[u] = dis[p]+1;
//     else dis[u] = 0;
//     for(auto v:adj[u]){
//         if(v!=p)
//             calcdis(v,u);
//     }
// }
// pair<int,int> calcdp(int u,int p){
void calcdp(int u, int p, int h){
    // dp[u] = dis[u]*a[u];
    res += a[u]*h;
    score[u] = a[u];
    for(auto v:adj[u]){
        if(v!=p){
            // dp[u] += calcdp(v,u).first;
            calcdp(v,u,h+1);//.second;
            score[u] += score[v];
        }
    }
    // cout<<dp[u]<<"\n";
    // return make_pair(dp[u], score[u]);
    // return score[u];
}
void solve(int u, int p){
    ans = max(ans, res);
    for(auto v:adj[u]){
        if(v!=p){
            res -= score[v];
            score[u] -=score[v];
            res += score[u];
            score[v] += score[u];
            solve(v,u);
            score[v] -= score[u];
            res -= score[u];
            score[u] += score[v];
            res += score[v];
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ans = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //calcdis(0,-1);
    calcdp(0,-1,0);
    //cout<<res<<"\n";
    // for(int i=0; i<n; i++){
    //     cout<<dp[i]<<" ";
    // }cout<<"\n";
    
    solve(0,-1);
    
    cout<<ans<<"\n";
}