#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e5;
const int maxn = 2505;
vector<int> adj[maxn];
int dis[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = INF;
    for(int u=1; u<=n; u++){
        fill(dis,dis+n+1, -1);
        queue<int> pq;
        dis[u] = 0;
        pq.push(u);
        while(!pq.empty()){
            int v = pq.front();
            pq.pop();
            for(auto t:adj[v]){
                if(dis[t] == -1){
                    dis[t] = dis[v]+1;
                    pq.push(t);
                }else if(dis[t] >= dis[v]){
                    ans = min(ans, 1+dis[v]+dis[t]);
                }
            }
        }
    }
    if(ans == INF) ans = -1;
    cout<<ans<<"\n";
}