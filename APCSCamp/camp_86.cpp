#include <iostream>
#include <vector>
#include <queue>
#include<cstring>

#define INF 0x3f3f3f3f
using namespace std;
#define int long long
int n,m,s,t;
vector<pair<int,int>> e[200010];
long long dis[200010];
bool vis[200010];

void dijkstra(int s, int t){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.emplace(0,s);
    while(!pq.empty()){
        int found = pq.top().second;
        pq.pop();
        if(vis[found]) continue;
        vis[found] = 1;
        for(pair<int,int> adj : e[found]){
            //cout<<adj.first<<" "<<adj.second<<"\n";
            if(!vis[adj.first] && dis[adj.first] > dis[found] + adj.second){
                dis[adj.first] = dis[found] + adj.second;
                //cout<<dis[adj.first]<<"\n";
                pq.emplace(dis[adj.first], adj.first);
            }
        }
    }
    //cout<<dis[t]<<"\n";
    long long ans = min(dis[t], dis[t+n]);
    if(ans > 1e15) ans = -1;
    cout<<ans<<'\n';
}
signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>s>>t;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        e[a].push_back(make_pair(b,w));
        e[a].push_back(make_pair(b+n,0));//被省略的免費機票
        e[a+n].push_back(make_pair(b+n, w));
    }
    dijkstra(s,t);
}
//actually not dat hard, but my dumb brain just can't