#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;

const int maxk = 2e5+5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int dp[maxk][7];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> s(k+2);
    s[0] = 0;
    s[k+1] = n*m;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        int p = (y-1)*m;
        p+=((y%2 == 0)?(m-x+1):x);
        // cout<<p<<"\n";
        if(p == n*m){
            cout<<"-1\n";
            exit(0);
        }
        s[i] = p;
    }
    sort(s.begin(), s.end());
    for(int i=1; i<=6 && (i<s[1]); i++) dp[0][i] = 1;
    for(int i=1; i<=k; i++){
        //cout<<s[i]<<"\n";
        for(int j=1; j<=6 && (s[i]+j<s[i+1]); j++){
            for(int a=1; a<=6; a++){
                int temp = dp[i-1][a] + (s[i]-s[i-1]-a+j+6)/6-1;
                dp[i][j] = min(temp, dp[i][j]);
                //cout<<temp<<"\n";
            }
            //cout<<dp[i][j]<<"\t"<<i<<"\n";
        }
    }
    int ans = INF;
    for(int a=1; a<=6; a++){
        int temp = (dp[k][a]+(n*m-s[k]-a+6)/6-1);
        //cout<<temp<<"\n";
        ans = min(temp, ans);
    }
    ans = (ans == INF?-1:ans);
    cout<<ans<<"\n";
}