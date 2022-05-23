#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
 
#define int long long
using namespace std;
 
const int maxn = 1e5+5, INF = 1e9;
vector<pair<int,int>> back[maxn],adj[maxn];
vector<int> order;
int n, e, par[maxn], cnt[maxn], deg[maxn]{0};
double sum[maxn];
 
bool get_ans(double m){
    fill(sum, sum+n+1, INF);
    fill(par, par+n+1, -1);
    fill(cnt, cnt+n+1, 0);
    for(auto i:order){
        if(back[i].size()){
            for(auto j:back[i]){
                if(sum[j.first]+j.second-m <= sum[i]){
                    sum[i] = sum[j.first]+j.second-m;
                    cnt[i] = cnt[j.first]+1;
                    par[i] = j.first;
                }
            }
        }else{
            sum[i] = 0;
        }
    }
    // cout << m <<"\t"<< sum[n] <<"\n";
    if(sum[n] >= 0){
        return 1;
    }else{
        return 0;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >>w;
        deg[v]++;
        adj[u].push_back({v,w});
        back[v].push_back({u,w});
    }
    // ( w_1 + w_2 + ... + w_i )/ i <= m
    // ( w_1-m + w_2-m + ... + w_i-m) <= 0
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    for(int i=1; i<=n; i++){
        if(q.empty())
            break;
        int s = q.front();
        q.pop();
        order.push_back(s);
        for(auto j:adj[s]){
            deg[j.first] --;
            if(!deg[j.first])
                q.push(j.first);
        }
    }
    // for(auto i:order){
    //     cout << i <<"\n";
    // }
    double l = 0, r = 105;
    while(l+1e-6<r){
        double m = (l+r)/2;
        if(get_ans(m)){
            l = m;
        }else{
            r = m;
        }
    }
    get_ans(l);
    // cout << l <<"\n";
    cout << cnt[n]<<"\n";
    vector<int> ans;
    int u = n;
    while(u != -1){
        ans.push_back(u);
        // cout <<u <<"\t"<<par[u]<<"\n";
        u = par[u];
    }
    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i] <<" ";
    }
    cout <<"\n";
}