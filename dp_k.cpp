#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int maxn = 1e5+5;
int s[101];
int dp[maxn];
int n,k;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    for(int i=0; i<k+1; i++){
        if(i >= s[0]){ //有可能是先手贏
            for(int j=0; j<n; j++){
                if(s[j] <= i && !dp[i-s[j]])
                    dp[i] = 1;
            }
        }else //後手必贏
            dp[i] = 0;
        //cout<<dp[i]<<"\n";
    }
    cout<<(!dp[k]?"Second":"First")<<"\n";
}