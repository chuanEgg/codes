#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1e6;
int dp[maxn][2];
//dp[i][1] -> selling at i
//dp[i][0] -> do nothing or buy at i

vector<pair<int,int>> last;
vector<int> adj[maxn];
vector<int> h;
vector<int> p;
int ans;
void DP(int i){
    for(auto j:adj[i]){
        for(auto price: last){
            int temp = price.second-p[j]; //profit of selling the item from "last" at j
            cout<<"\t"<<temp<<"\n";
            dp[j][1] = max(dp[j][1], dp[price.first][0]+temp);
        }
        dp[j][0] = max(dp[i][0],dp[i][1]);
        cout<<dp[j][0]<<"\t"<<dp[j][1]<<"\n";
        ans = max(ans, max(dp[j][0], dp[j][1]));
        cout<<i<<" "<<j<<" "<<ans<<"\n";
        last.push_back(make_pair(j,p[j]));
        DP(j);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    ans = 0;
    int n,m;
    cin>>n>>m;
    p.resize(n);
    for(int i=0; i<n; i++) cin>>p[i+1];
    h.resize(n, 0);
    for(int i=0; i<m; i++){
        int f,t;
        cin>>f>>t;
        adj[f].push_back(t);
        h[t]++;
    }
    for(int i=0; i<n; i++){
        if(!h[i]){
            last.clear();
            last.push_back(make_pair(i,p[i]));
            DP(i);
        }
    }
    cout<<ans<<'\n';
}