#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n,k;
const int maxn = 1e5+5;
int deg[maxn], dp[maxn];
vector<int> e[maxn], back[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    cin>>n>>k;
    for(int i=1; i<=k; i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        back[v].push_back(u);
        deg[v]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(deg[i] == 0)
            q.push(i);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(q.empty()) break;
        int s = q.front();
        q.pop();
        deg[s] = -1;
        //cout<<s;
        if(back[s].size()){
            for(auto j:back[s])
                dp[s] = max(dp[s], dp[j]+1);
        }else{
            dp[s] = 0;
        }
        ans = max(ans, dp[s]);
        for(auto j:e[s]){
            deg[j]--;
            if(!deg[j]) q.push(j);
        }
    }
    cout<<ans<<"\n";
}