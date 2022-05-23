#include <iostream>
#include <cstring>

using namespace std;
#define int long long
int s[3001];
int dp[3001][3001];

int f(int l,int r, int round){
    if(dp[l][r]!=0){
        return dp[l][r];
    }
    if(l>(r-1)){
        if(round==1)
            return dp[l][r]=s[l];
        return dp[l][r]=-1*s[l];
    }
    if(round==1){
        return dp[l][r]=max(f(l+1,r,2)+s[l], f(l,r-1,2)+s[r]);
    }else{
        return dp[l][r]=min(f(l+1,r,1)-s[l], f(l,r-1,1)-s[r]);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,temp;
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    cout<<f(0,(n-1),1)<<"\n";
}