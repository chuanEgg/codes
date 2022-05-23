#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn], ans;
int vis[maxn]{0}, inst[maxn]{0};
stack<int> st;

void dfs(int u){
    vis[u] = 1;
    st.push(u);
    inst[u] = 1;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }else if(inst[v]){
            int temp;
            do{
                temp = st.top();
                st.pop();
                ans.push_back(temp);
            }while(temp != v);
            reverse(ans.begin(), ans.end());
            ans.push_back(v);
            cout << ans.size() <<"\n";
            for(auto i:ans){
                cout << i <<" ";
            }
            cout <<"\n";
            exit(0);
        }
    }
    st.pop();
    inst[u] = 0;
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
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE\n";
}