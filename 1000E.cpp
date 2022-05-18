#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+5;
vector<int> adj[maxn], bcc_adj[maxn];
vector<pair<int,int>> edge;
int dfn[maxn], low[maxn], bcc[maxn];
int t = 0, bccid = 0, ans = 0;
stack<int> st;

void dfs(int u, int p){
    dfn[u] = low[u] = ++t;
    st.push(u);
    for(auto v:adj[u]){
        if(v == p) continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        ++bccid;
        int temp;
        do{
            temp = st.top();
            st.pop();
            bcc[temp] = bccid;
        }while(temp != u);  
    }
}

void build_bcc(){
    for(auto p:edge){
        int u = p.first, v = p.second;
        if(bcc[u] != bcc[v]){
            bcc_adj[bcc[u]].push_back(bcc[v]);
        }
    }
}
int get_ans(int u, int p){
    int h1 = 0, h2 = 0;
    for(auto v:bcc_adj[u]){
        if(v == p) continue;
        int h = get_ans(v, u) + 1;
        if(h > h1){
            h2 = h1;
            h1 = h;
        }else if(h > h2){
            h2 = h;
        }
    }
    ans = max(ans, h1+h2);
    return h1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    
        edge.push_back({v, u});
        edge.push_back({u, v});
    }
    dfs(1, 0);
    build_bcc();
    get_ans(1, 0);
    cout << ans <<"\n";
}
/*
5 5
1 2
2 3
3 1
4 1
5 2
*/