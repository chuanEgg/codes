#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 1e5+5;
int n,mod;
int dp[maxn], ans[maxn];
vector<int> adj[maxn];

int build(int u, int p){
    dp[u] = 1;
    for(auto v:adj[u]){
        if(v!=p){
            dp[u] *= (1+build(v,u));
            dp[u] %= mod;
        }
    }
    return dp[u];
}
void solve(int u, int p, int top){
    vector<int> temp;
    for(auto v:adj[u]){
        if(v == p){
            temp.push_back(1+top);
        }else{
            temp.push_back(1+dp[v]);
        }
    }
    if(temp.size() == 0){
        ans[u] = 1;
        return;
    }
    vector<int> pref(temp.size(), 1);
    vector<int> suff(temp.size(), 1);
    pref.front() = temp.front()%mod;
    for(int i=1; i<temp.size(); i++){
        pref[i] = (pref[i-1]*temp[i]) %mod;
    }
    suff.back() = temp.back() %mod;
    for(int i=temp.size()-2; i>=0; i--){
        suff[i] = (suff[i+1]*temp[i]) %mod;
    }
    ans[u] = pref.back() %mod;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != p) {
            int prod1 = ((i > 0) ? pref[i - 1]: 1);
            int prod2 = ((i != temp.size()-1) ? suff[i + 1]: 1);
            solve(v, u, (prod1 * prod2) % mod);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>mod;
    for(int i=0; i<n-1; i++){
        int f,t;
        cin>>f>>t;
        f--; t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    build(0,-1);
    solve(0,-1,0);
    for(int i=0; i<n; i++){
        cout<<ans[i]%mod<<"\n";
    }
}