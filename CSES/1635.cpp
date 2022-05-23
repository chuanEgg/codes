#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,c;
    cin>>n>>c;
    vector<int> coin(n), dp(c+1);
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }
    dp[0] = 1;
    for(int i=1; i<=c; i++){
        for(int j=0; j<n; j++){
            if(i-coin[j] >= 0){
                dp[i]+=dp[i-coin[j]];
                dp[i] %= mod;
            }
        }
    }
    cout<<dp[c]<<"\n";
}