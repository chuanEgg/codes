#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        int v[n], c[n];
        for(int i = 0 ; i < n ; i++){
            cin>>v[i]>>c[i];
        }
        int dp[n+1][101]={0};
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= 100 ; j++){
                if(v[i] > 100){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i+1][j-v[i]]+c[i]);
                }
            }
        }
        cout<<dp[0][100]<<endl;
    }
}