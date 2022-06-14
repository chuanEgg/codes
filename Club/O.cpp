#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+5;
int dsu[maxn];
int find(int u){
    return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}
void unite(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return;
    dsu[u] = v;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> par(n);
    for(int i=0; i<n; i++){
        cin >> par[i];
    }
}