#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

const int maxn = 5005;
const int INF = 1e18;
int adj[maxn][maxn];
struct S{
    int x,y,z;
};
struct edge{
    int w = INF, to = -1;
};
int cost(S c, S d){
    return pow(c.x - d.x, 2) + pow(c.y - d.y, 2) + pow(c.z - d.z, 2);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<S> point(n);
    for(int i=0; i<n; i++){
        cin>>point[i].x>>point[i].y>>point[i].z;
        for(int j=i; j>=0; j--){
            if(i == j){ adj[i][j] = INF; continue;}
            int temp = cost(point[i],point[j]);
            adj[i][j] = temp;
            adj[j][i] = temp;
        }
    }
    int ans = 0;
    vector<bool> selected(n,0);
    vector<edge> min_e(n);
    min_e[0].w = 0;
    for(int i=0; i<n; i++){
        int v = -1;
        for(int j=0; j<n; j++){
            if(!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }
        selected[v] = true;
        ans += min_e[v].w;
        for(int to = 0; to<n; to++){
            if(adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }
    cout<<ans<<"\n";
}