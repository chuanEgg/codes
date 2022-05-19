#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

const int maxn = 1e5+5;
int n;
vector<pair<int,int>> adj[maxn];
//pair<int,int> res[maxn];
pair<int,int> ans;

pair<int,int> update(int h1, int h2, int temph1, int temph2){
    int arr[5] = {h1, h2, temph1, temph2, 0};
    sort(arr,arr+4,greater<int>());
    int x = 0;
    for(int i=1; i<5; i++){
        if(arr[i] != arr[0])
            x = arr[i]; break;
    }
    return make_pair(arr[0], x);
}
void add(int temp){
    if(ans.first < temp)
        ans = make_pair(temp, ans.first);
    else if(ans.first != temp && ans.second < temp)
        ans.second = temp;
}
pair<int,int> dfs(int u, int p){
    int h1 = 0, h2 = 0;
    for(auto i:adj[u]){
        int v = i.first;
        int w = i.second;
        if(v!=p){
            auto h = dfs(v,u);
            int temph1 = h.first+w;
            int temph2 = h.second+w;
            add(temph1 + h1);
            add(temph1 + h2);
            add(temph2 + h1);
            //cout<<u<<" "<<h1<<" "<<h2<<" "<<temph1<<" "<<temph2<<"\n";
            auto temp = update(h1, h2, temph1, temph2);
            h1 = temp.first;
            h2 = temp.second;
        }
    }
    //cout<<u<<" "<<h1<<" "<<h2<<"\n";
    //res[u] = make_pair(h1,h2);
    return make_pair(h1,h2);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(0,-1);
    // res.pop();
    // cout<<res.top()<<"\n";
    cout<<ans.second<<"\n";
}