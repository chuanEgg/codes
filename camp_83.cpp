#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5+1;
vector<int> e[maxn];
int sz[maxn], n;
int mn = maxn;
vector<int> res;

void dfs(int x, int y){
    sz[x] = 1;
    int mx = 0;//慘度
    for(auto i:e[x]){
        if(i==y) continue;
        dfs(i,x);
        sz[x]+=sz[i];
        mx = max(mx, sz[i]);
    }
    mx = max(mx, n-sz[x]);
    if(mx < mn){
        mn = mx;
        res.clear();
        res.emplace_back(x);
    }else if(mx == mn){
        res.emplace_back(x);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++){
        int f,t;
        cin>>f>>t;
        e[f].push_back(t);
        e[t].push_back(f);
    }
    dfs(0,-1);
    sort(res.begin(), res.end());
    for(auto i: res){
        cout<<i<<"\n";
    }
}