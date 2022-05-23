#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, s[5001], dp[5001];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
        dp[i]=1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(s[j]<s[i])
                dp[i]=max(dp[i], dp[j]+1);
        }
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans, dp[i]);
    }
    cout<<ans<<"\n";
}