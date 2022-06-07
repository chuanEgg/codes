#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define U second.first
#define V second.second
#define int long long

const int maxn = 1e5+5;

int dsu[maxn], dsu2[maxn];
vector<pair<int,int>> update;

int find(int u){
    return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}
int find2(int u){
    return dsu2[u]==u ? u : dsu2[u] = find2(dsu2[u]);
}
 
void uni(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return;
    dsu[u] = v;
}
void uni2(int u, int v){
    u = find2(u), v = find2(v);
    if(u==v) return;
    dsu2[u] = v;
    update.push_back({u, v});
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    iota(dsu, dsu + n+1, 0);
    iota(dsu2, dsu2 + n+1, 0);
    vector<pair<int, pair<int,int>>> E(m);
    for(int i=0; i<m; i++){
        cin >> E[i].U >> E[i].V >> E[i].first;
        // cout << E.back().first <<"\n";
    }
    sort(E.begin(), E.end());
    int lst = E[0].first, pos = 0, ans = 0;
    for(int i=0; i<m; i++){
        if(E[i].first != lst){
            for(auto j:update){
                // cout << j <<"\n";
                uni(j.first, j.second);
            }
            update.clear();
            pos = i;
            lst = E[i].first;
        }
        // cout << find2(E[i].U) << ' '<< find2(E[i].V) <<'\n';
        if(find2(E[i].U) == find2(E[i].V) && find(E[i].U) != find(E[i].V)){
            ans ++;
            // cout << E[i].U << ' ' << E[i].V << "\n";
        }else
        uni2(E[i].U, E[i].V);
    }
    cout << ans <<'\n';
}