#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 105, INF = 1e18;
vector<pair<int,int>> adj[maxn];
int dis[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, s, e, f;
        cin >> n >> m >> s >> e >> f;
        s--, e--;
        for(int i=0; i<n; i++){
            adj[i].clear();
        }
        fill(dis, dis+n, INF);
        for(int i=0; i<m; i++){
            int u, v, w1, d, w2, w;
            cin >> u >> v >> w1 >> d >> w2;
            u--, v--;
            w = min(d, f)*w1 + max(0LL, f-d)*w2;
            adj[u].push_back({v, w});
        }
        dis[s] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({dis[s], s});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int u = temp.second;
            if(temp.first > dis[u])
                continue;
            for(auto i:adj[u]){
                int v = i.first;
                int w = i.second;
                if(dis[v] > dis[u]+w){
                    dis[v] = dis[u]+w;
                    pq.push({dis[v], v});
                }
            }
        }
        cout << dis[e] <<"\n";
    }
}