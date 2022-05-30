#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 2e5+5, INF = 1e16;
vector<pair<int,int>> adj[maxn], back[maxn];
int dis1[maxn], dis2[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        back[v].push_back({u, w});
    }
    fill(dis1, dis1+n, INF);
    fill(dis2, dis2+n, INF);
    dis1[0] = 0;
    dis2[n-1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({dis1[0], 0});
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int u = temp.second;
        if(temp.first > dis1[u])
            continue;
        for(auto i:adj[u]){
            int v = i.first;
            int w = i.second;
            if(dis1[v] > dis1[u]+w){
                dis1[v] = dis1[u]+w;
                pq.push({dis1[v], v});
            }
        }
    }
    pq.push({dis2[n-1], n-1});
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int u = temp.second;
        if(temp.first > dis2[u])
            continue;
        for(auto i:back[u]){
            int v = i.first;
            int w = i.second;
            if(dis2[v] > dis2[u]+w){
                dis2[v] = dis2[u]+w;
                pq.push({dis2[v], v});
            }
        }
    }
    
    while(q--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << min(dis1[n-1], dis1[u] + dis2[v] + 1) <<"\n";
    }
}