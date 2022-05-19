#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
const int maxn = 1e6+5;
int dp[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    dp[0] =1;
    for(int i=1; i<=n; i++){
        for(int j=i-6; j<i; j++){
            if(j>=0){
                dp[i]+=dp[j];
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[n]<<"\n";
}