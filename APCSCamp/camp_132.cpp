#include <iostream>
#include <cstring>

using namespace std;
#define INF 0x3f3f3f3f

int m,n;
int s[27][27], dp[27][27][27][27], used[27][27][27][27];

int bruh(int l, int r, int u, int d){
    int b=0, w=0;
    for(int i=l; i<=r; i++){
        for(int j=u; j<=d; j++){
            if(s[i][j]==1) b++;
            else w++;
        } 
    }
    //cout<<b<<"\t"<<w<<"\n";
    return min(b, w);
}
int DP(int l ,int r, int u, int d){
    if(l>r||d<u) return 0;
    if(used[l][r][u][d]) return dp[l][r][u][d];
    used[l][r][u][d]=1;
    dp[l][r][u][d] = 1e9;
    //cout<<"hi\n";
    dp[l][r][u][d] = min(dp[l][r][u][d], DP(l+1,r,u,d)+bruh(l,l,u,d));
    dp[l][r][u][d] = min(dp[l][r][u][d], DP(l,r-1,u,d)+bruh(r,r,u,d));
    dp[l][r][u][d] = min(dp[l][r][u][d], DP(l,r,u+1,d)+bruh(l,r,u,u));
    dp[l][r][u][d] = min(dp[l][r][u][d], DP(l,r,u,d-1)+bruh(l,r,d,d));
    return dp[l][r][u][d];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    memset(used,0,sizeof(used));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>s[i][j];
        }
    }
    cout<<DP(1,n,1,m)<<"\n";
}