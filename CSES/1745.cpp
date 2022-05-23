#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
bool dp[maxn][1000*maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(0));
    int n, sum = 0;
    cin>>n;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
        sum+=s[i];
    }
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        dp[i][0] = 1;
        for(int j=0; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            int l = j-s[i-1];
            if(l>=0 && dp[i-1][l]){
                dp[i][j] = 1;
            }
        }
    }
    vector<int> ans;
    for(int i=1; i<=sum; i++){
        if(dp[n][i]) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}