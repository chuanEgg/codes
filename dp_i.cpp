#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

double s[3000], dp[3000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j>=0; j--){
            if(j==0){
                dp[j] = dp[j]*(1-s[i]);
            }else{
                dp[j] = dp[j-1]*(s[i]) + dp[j]*(1-s[i]);
            }
            //cout<<dp[j]<<" ";
        }
        //cout<<endl;
    }
    double ans = 0;
    for(int i=0;i<=n; i++){
        int t = n-i;
        if(t<i)
            ans += dp[i];
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
}