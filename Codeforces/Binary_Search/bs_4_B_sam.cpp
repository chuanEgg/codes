#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adj[N];
int deg[N], tmpdeg[N], from[N];
double dp[N];
int n,m;


bool check(double x){
    for(int i = 1;i <= n;i++){
        deg[i] = tmpdeg[i];
    }

    fill(from,from+N,0);
    fill(dp,dp+N,1e18);

    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(deg[i]==0) q.push(i);
    }

    dp[1] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto [v,w] : adj[u]){
            if(dp[v] > dp[u] + w - x){
                dp[v] = dp[u] + w - x;
                from[v] = u;
            }
            deg[v]--;
            if(deg[v]==0) q.push(v);
        }
    }

    return dp[n] <= 0;
}

signed main(){
    fastio
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        tmpdeg[v]++;
    }

    double l = 0, r = 150;
    for(int i = 0;i < 100;i++){
        double mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }

    // cout << l << "\n";
    check(l);

    vector<int> ans;
    int x = n;
    do{
        ans.push_back(x);
        x = from[x];
    }while(x != 0);

    cout << ans.size()-1 << "\n";
    reverse(ans.begin(),ans.end());
    for(auto x : ans) cout << x << " ";
}