#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int maxn = 2.5e3+5;
vector<pair<int,int>> adj[maxn];
int dis[maxn], par[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int u,v,w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    memset(dis,0x3f,sizeof(dis));
    memset(par,0,sizeof(par));
    dis[1] = 0;
    int temp = 0;
    for(int i=0; i<n+1; i++){
        temp = 0;
        for(int j=1; j<n+1; j++){
            for(auto p:adj[j]){
                if(dis[p.first] > dis[j]+p.second){
                    dis[p.first] = dis[j]+p.second;
                    par[p.first] = j;
                    temp = p.first;
                }
            }
        }
    }
    if(temp == 0){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i=0; i<n; i++){
        temp = par[temp];
    }
    vector<int> cyc;
    for(int i = temp;; i=par[i]){
        cyc.push_back(i);
        if(i == temp && cyc.size() > 1){
            break;
        }
    }
    reverse(cyc.begin(), cyc.end());
    for(auto i:cyc){
        cout<<i<<" ";
    }cout<<"\n";
}