#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

const int maxn = 1505;
int dsu[maxn], sz[maxn], N, cnt, clear[maxn];

int find(int u){
    return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}
void uni(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return;
    if(sz[u] < sz[v]) swap(u, v);
    dsu[v] = u;
    sz[u] += sz[v];
}
void initialize(int n){
    iota(dsu, dsu+n, 0);
    fill(sz, sz+n, 1);
    fill(clear, clear+n, 0);
    N = n;
    cnt = 0;
}
int hasEdge(int a, int b){
    if(find(a) != find(0)) swap(a,b);
    // cout << a <<"\t"<<clear[a]<<"\t"<<sz[find(a)]<<"\n";
    // cout << b <<"\t"<<clear[b]<<"\t"<<sz[find(b)]<<"\n";
    if(find(a) == find(0) && clear[b] == N-2){
        uni(a, b);
        return 1;
    }else{
        clear[a]++;
        clear[b]++;
        return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    int n;
    cin >> n;
    initialize(n);
    for(int i=0; i< n*(n-1)/2; i++){
        int u, v;
        cin >> u >> v;
        cout << hasEdge(u, v) <<"\n";
    }
}