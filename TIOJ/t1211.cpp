#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int INF = 1e18;
const int maxn = 1e4+5;
struct edge{
    int x,y,cost;
};
bool cmp(edge x, edge y){
    return x.cost < y.cost;
}
int parent[maxn];
vector<edge> adj;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m && (n||m)){
        int ans = 0;
        adj.clear();
        for(int i=1; i<=n; i++)
            parent[i] = i;
        for(int i=0; i<m; i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj.push_back({u,v,w});
        }
        sort(adj.begin(), adj.end(), cmp);
        for(auto i:adj){
            int u = find(i.x);
            int v = find(i.y);
            if(u == v) continue;
            parent[v] = u;
            ans += i.cost;
            n--;
        }
        if(n > 1) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
}