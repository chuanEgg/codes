#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int, int> P;
int dis[200001];
vector<P> edge[200001];
int par[200001];
stack<int> temp;
void find(int u){
    temp.push(u+1);
    if(par[u] == u){
        return;
    }
    find(par[u]);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, b, w, d;
    cin >> n >> m;
    priority_queue<P, vector<P>, greater<>> pq;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        a--; b--;
        edge[a].push_back(P(b, w));
        edge[b].push_back(P(a, w));
    }
    //memset(par, 0x3f, sizeof(par));
    par[0] = 0;
    // memset(dis, 0x3f, sizeof(dis));
    fill(dis,dis+n,INF);
    dis[0] = 0;
    pq.push(P(0, 0));
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        d = p.first; a = p.second;
        if(d > dis[a]) continue;
        for(auto i: edge[a]){
            b = i.first; d = i.second;
            if(dis[b] > dis[a] + d){
                par[b] = a;
                dis[b] = dis[a] + d;
                pq.push(P(dis[b], b));
            }
        }
    }
    n--;
    if(dis[n] == INF) cout << "-1";
    else{
        // stack<int> temp;
        // for(int i = n - 1; i != par[i]; i = par[i]) 
        //     temp.push(i + 1);
        // temp.push(1);
        // while(temp.size()){
        //     cout << temp.top() << " "; temp.pop();
        // }
        find(n);
    }
    while(!temp.empty()){
        int res = temp.top();
        temp.pop();
        cout<<res<<" ";
    }
    cout << "\n";
    return 0;
}