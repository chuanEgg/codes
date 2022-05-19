#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
const int maxn = 50005;
int f[maxn];
int group[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>f[i];
    }    
    memset(group, -1, sizeof(group));
    for(int i=0; i<n; i++)
    {
        if(group[i] >= 0) continue;
        group[i] = i;//default set oneself as own root
        int now = i;
        while(f[now]!= i){
            group[f[now]] = i;
            now = f[now];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += (group[i] == i);
    }
    cout<<ans<<"\n";

}