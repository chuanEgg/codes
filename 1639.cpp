#include <iostream>

using namespace std;

int dp[5005][5005];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    dp[0][0]=0;
    int n=a.length(), k=b.length();
    int maxl=max(n,k);
    for(int i=1; i<=maxl; i++){
        dp[i][0]=i;
        dp[0][i]=i;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j];
            else dp[i+1][j+1]=min(min(dp[i+1][j], dp[i][j+1]), dp[i][j])+1;
        }
    }
    cout<<dp[n][k]<<"\n";
}