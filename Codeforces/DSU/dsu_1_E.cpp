#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

const int maxn = 2e5+5;
set<pair<int,int>> s;
int dsu[maxn], sz[maxn]{1}, hand[maxn][2]{-1}, ans[maxn];
vector<int> child[maxn];

int find(int u){
    if(dsu[u] == u)
        return u;
    return dsu[u] = find(dsu[u]);
}
void uni(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(u != find(1)) swap(u, v);
    while(!child[v].empty()){
        ans[child[v].back()] = ans[v];
        // cout << child[v].back() <<"\t"<<v<<"\t"<<ans[v]<<"\n";
        child[u].push_back(child[v].back());
        child[v].pop_back();
    }
    dsu[v] = u;
    sz[u] += sz[v];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    iota(dsu, dsu+n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> hand[i][0] >> hand[i][1];
        if(hand[i][0] != -1){
            s.insert({hand[i][0], i});
        }
        if(hand[i][1] != -1){
            s.insert({hand[i][1], i});
        }
        child[i].push_back(i);
        ans[i] = -1;
    }
    vector<pair<int,int>> q(m);
    for(int i=0; i<m; i++){
        cin >> q[i].first >> q[i].second;
        s.erase({hand[q[i].first][q[i].second-1], q[i].first});
    }
    for(auto p:s){
        int u = p.first, v = p.second;
        uni(u, v);
    }
    // for(int i=1; i<=n; i++){
    //     cout << dsu[i] <<" ";
    // }cout << "\n";
    for(int i=m-1; i>=0; i--){
        int p = q[i].first, h = q[i].second;
        h--;
        if(find(hand[p][h]) == find(1) && find(p) == find(1)) continue;
        if(find(p) == find(1)){
            ans[find(hand[p][h])] = i;
            // cout << hand[p][h] << " "<<i<<"(p)\n";
        }else if(find(hand[p][h]) == find(1)){
            ans[find(p)] = i;
            // cout << p << " "<<i<<"(hand)\n";
        }
        uni(hand[p][h], p);
        // for(int i=1; i<=n; i++){
        //     cout << dsu[i] <<" ";
        // }cout << "\n";
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] <<"\n";
    }
}