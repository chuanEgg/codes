#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5, mod = 1e6+7;
int dp[maxn][3][3];
//     i-th  h  t
//0->R/ 1->G/ 2->B

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=0; i<=2; i++)
        dp[1][i][i] = 1;
    for(int i=0; i<=2; i++)
        for(int j=0; j<=2; j++)
            dp[2][i][j] = 1;
    dp[2][1][2] = dp[2][2][1] = 0;
    for(int i=3; i<=1e5; i++){
        for(int j=0; j<=2; j++){
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2];
            dp[i][j][1] = dp[i][j][0] - dp[i-1][j][2];
            dp[i][j][2] = dp[i][j][0] - dp[i-1][j][1];
            for(int w=0; w<=2; w++) dp[i][j][w] %= mod;
        }
    }
    while(t--){
        int n;
        cin >> n;
        if(n == 1) cout << "3\n";
        else if(n == 2) cout << "7\n";
        else{
            int res = 0;
            for(int i=0; i<=2; i++){
                res += dp[n][i][i];
            }
            res += dp[n][0][1]+dp[n][0][2];
            res += dp[n][1][0]+dp[n][2][0];
            res %= mod;
            cout << res <<"\n";
        }
        
    }
}