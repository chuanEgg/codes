#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define int long long
using namespace std;

const int maxn = 4e5+1;
bool gone[maxn], no[maxn];
int cnt[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(gone,0,sizeof(gone));
        memset(cnt,0,sizeof(cnt));
        int n,k,node;
        cin>>n>>k;
        node = n;
        vector<int> graph[n+1];
        for(int i=0; i<n-1; i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cnt[u]++;
            cnt[v]++;
        }
        for(int i=0; i<k; i++){
            if(!node) break;
            for(int i = 1; i<=n; i++){
                if(cnt[i] == 1 && !gone[i] &&!no[i]){
                    //cout<<"\t"<<i<<"\n";
                    node--;
                    gone[i] = 1;
                    for(auto j:graph[i]){
                        cnt[j]--;
                        no[j]=1;
                    }
                }
            }
            memset(no,0,sizeof(no));
        }
        
        cout<<node<<"\n";
    }
}