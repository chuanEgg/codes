#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#define int long long
using namespace std;

const int maxn = 2e5+5;
const int INF = 1e13;

vector<pair<int,int>> adj[maxn];
int dis[maxn];
int par[maxn];
stack<int> res;

void find(int u){
    res.push(u+1);
    if(par[u] == u){
        return;
    }
    find(par[u]);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    fill(dis,dis+n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
    dis[0] = 0;
    par[0] = 0;
    pq.push(make_pair(dis[0], 0));
    while(!pq.empty()){
        pair<int,int> t = pq.top();
        pq.pop();
        int u = t.second;
        if(t.first > dis[u]) continue;
        for(pair<int,int> i:adj[u]){
            int v = i.first;
            int w = i.second;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                par[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
    --n;
    if(dis[n] == INF)
        cout<<"-1\n";
    else
        find(n);
    while(!res.empty()){
        int temp = res.top();
        res.pop();
        cout<<temp<<" ";
    }
    cout<<"\n";
}