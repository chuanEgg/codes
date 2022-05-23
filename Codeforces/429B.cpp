#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1001][1001];
long long dp1[1001][1001], dp2[1001][1001], dp3[1001][1001], dp4[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    memset(dp3,0,sizeof(dp3));
    memset(dp4,0,sizeof(dp4));
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    for (int j = m; j >= 1; --j)
        for (int i = 1; i <= n; ++i)
            dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = a[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);
    long long ans = 0;
    for(int i=2; i<=n-1; i++){
        for(int j=2; j<=m-1 ;j++){
            ans = max(ans, dp1[i][j-1]+dp2[i-1][j]+dp3[i+1][j]+dp4[i][j+1]);
            ans = max(ans, dp1[i-1][j]+dp2[i][j+1]+dp3[i][j-1]+dp4[i+1][j]);
        }
    }
    cout<<ans<<"\n";
}