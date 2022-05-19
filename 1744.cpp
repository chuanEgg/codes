#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    int a,b;
    cin>>a>>b;
    for(int i=0; i<= max(a,b); i++){
        dp[i][i]=0;
        dp[i][0]=0;
        dp[0][i]=0;
    }
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i == j) dp[i][j] = 0;
            else{
                for(int k=1; k<i; k++){
                    dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
                }
                for(int k=1; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
                }
            }
        }
    }
    cout<<dp[a][b]<<"\n";
}