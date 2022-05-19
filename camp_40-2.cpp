#include <iostream>

using namespace std;
#define maxn 501

long long dp[maxn][maxn*6+1];

int main(){
    dp[0][0]=1;
    for(int i=1; i<501; i++){//dice
        for(int j=i; j<=6*i; j++){//total sum
            dp[i][j]=0;
            for(int k=1; k<=6; k++){
                if(j-k>=i-1 && j-k<=6*(i-1)){
                    dp[i][j] += dp[i-1][j-k];
                    dp[i][j]%=998244353;
                }
            }
        }

    }
    int cnt;
    cin>>cnt;
    while(cnt--){
        int n,m;
        cin>>n>>m;
        cout<<dp[n][m]<<"\n";
    }
}