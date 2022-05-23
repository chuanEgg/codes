#include<iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,int> P;

bool pass[11];
int ans;
int n, m, start;
vector<pair<int,int>> v[11];
void dfs(int ,int ,int);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(pass,0,sizeof(pass));
    ans=1e9;
    cin>>n>>m;
    int f,t,w;
    for(int i=0; i<m; i++){
        cin>>f>>t>>w;
        v[f].push_back(P(t,w));
        v[t].push_back(P(f,w));
    }
    start=1;
    pass[1]=1;
    for(auto i:v[1]){
        pass[i.first]=1;
        int sum=i.second;
        dfs(i.first,sum,2);
        pass[i.first]=0;
    }
    if(ans==1e9)
        cout<<"-1\n";
    else
        cout<<ans<<'\n';
}

void dfs(int t, int w, int curcnt){
    if(curcnt == n){
        for(auto i:v[t]){
            if(i.first == start){
                w+=i.second;
                ans=min(ans,w);
                return;
            }
        }
        return;
    }
    pass[t] = 1;
    for(auto i:v[t]){
        if(pass[i.first])
            continue;
        pass[i.first] = 1;
        curcnt++;
        w+=i.second;
        dfs(i.first, w, curcnt);
        pass[i.first] = 0;
        curcnt--;
        w -= i.second;
    }
}