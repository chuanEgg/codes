#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 5e3+2, mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    if(sum%2){
        cout<<"0\n";
        return 0;
    }
    sum /=2;
    vector<vector<int>> dp(n,(vector<int>(sum+1,0)));
    dp[0][0] =1;
    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            int l = j-i;
            if(l>=0){
                dp[i][j]+=dp[i-1][l];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n-1][sum]<<"\n";
}