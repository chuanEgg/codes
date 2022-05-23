#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

const int maxn = 1e5+5;
int dsu[maxn];

int find(int u){
    if(dsu[u] == u)
        return u;
    return dsu[u] = find(dsu[u]);
}
void uni(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    dsu[u] = v;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    iota(dsu, dsu+n+1, 0);
    while(m--){
        string o;
        int u, v;
        cin>>o>>u>>v;
        if(o == "union"){
            uni(u, v);
        }else{
            if(find(u) == find(v)){
                cout <<"YES\n";
            }else{
                cout <<"NO\n";
            }
        }
    }
}