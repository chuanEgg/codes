#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
int deg[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0; i<n; i++)
            adj[i].clear();
        memset(deg, 0, sizeof(deg));
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            deg[v]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            if(deg[i] == 0)
                pq.push(i);
        }
        vector<int> ans;
        while(!pq.empty()){
            int u = pq.top();
            pq.pop();
            ans.push_back(u);
            for(auto v:adj[u]){
                deg[v] --;
                if(deg[v] == 0)
                    pq.push(v);
            }
        }
        if(ans.size() != n){
            cout << "QAQ\n";
        }else{
            for(int i=0; i<n; i++)
                cout << ans[i] << (" \n"[i == n-1]);
        }
    }
}