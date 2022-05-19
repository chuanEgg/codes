#include <iostream>

using namespace std;

int dp[53][10003], dp2[53][10003];

int main(){
    int m,n,s[53][10003];
    cin>>m>>n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>s[i][j];
            if(i==1){
                dp[i][j]=max(s[i][j], dp[i][j-1]+s[i][j]);
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1])+s[i][j];
            }
        }
    }
    cout<<endl;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int ans=0;
    for(int i=1; i<=m; i++){
        for(int j=n; j>=0; j--){
            if(i==1){
                dp2[i][j]=max(dp2[i][j+1]+s[i][j], s[i][j]);
            }else{
                dp2[i][j]=max(dp[i-1][j],dp2[i][j+1])+s[i][j];
            }
            dp[i][j]=max(dp2[i][j],dp[i][j]);
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout<<dp2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<=n; i++){
        ans=max(ans,dp[m][i]);
    }
    cout<<ans<<"\n";

}