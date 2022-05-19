#include <iostream>

using namespace std;

int ans=0;
int sum=0;
int n,m;
int dp[501];
void dfs(int i){
    if(i>n){
        if(sum==m){
            ans++;
        }
    }else{
        for(int j=1; j<=6; j++){
            sum+=j;
            dfs(i+1);
            sum-=j;
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        ans=0; sum=0;
        cin>>n>>m;
        dfs(1);
        cout<<ans<<endl;
    }
}//TLE