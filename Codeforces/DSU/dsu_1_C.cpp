#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5+5;
int score[maxn]{0}, ans[maxn]{0}, par[maxn];
vector<int> dsu[maxn];

int find(int u){
    if(u == par[u])
        return u;
    return par[u] = find(par[u]);
}
void uni(int u, int v){
    u = find(u), v = find(v);
    if(u == v){
        return;
    }
    if(dsu[u].size() < dsu[v].size()) swap(u,v);
    par[v] = u;
    while(!dsu[v].empty()){
        ans[dsu[v].back()] -= score[u]-score[v];
        dsu[u].push_back(dsu[v].back());
        dsu[v].pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dsu[i].push_back(i);
        par[i] = i;
    }
    while(m--){
        string o;
        int u, v;
        cin >> o;
        if(o == "add"){
            cin >> u >>v;
            u = find(u);
            score[u]+=v;
        }else if(o == "join"){
            cin >> u >> v;
            uni(u ,v);
        }else{
            cin >> u;
            cout << ans[u]+score[find(u)]<<"\n";
        }
    }
}