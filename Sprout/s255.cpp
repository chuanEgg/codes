#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,avx,avx2")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 25, INF = 30;
int bitmask[maxn];

struct node{
    int x, y;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    bitmask[0] = 1;
    for(int i=1; i<maxn; i++)
        bitmask[i] = (bitmask[i-1]<<1);
    
    while(t--){
        int n;
        cin >> n;
        vector<node> s(n);
        for(int i=0 ; i<n; i++)
            cin >> s[i].x >> s[i].y;
        
        vector<vector<int>> pass(n, vector<int>(n, 0));
        //pass[{a, b}] -> points on ax^2 + bx 
        // vector<int> mx(n, 0);
        for(register int i=0; i<n; i++){
            for(register int j=i+1; j<n; j++){
                double delta = s[i].x * s[j].x * (s[i].x - s[j].x);
                double a = (s[j].x * s[i].y - s[i].x * s[j].y)/delta;
                double b = (s[i].x * s[i].x * s[j].y - s[j].x * s[j].x * s[i].y)/delta;
                if(delta == 0 || a >= 0) continue;
                for(int k = 0; k<n; k++){
                    if(abs(s[k].x * s[k].x * a + s[k].x * b - s[k].y) <= 1e-7){
                        pass[i][j] |= bitmask[k];
                    }
                }
            }
        }

        int all = bitmask[n]-1;
        vector<int> dp(1<<n, INF);
        dp[0] = 0;
        
        for(register int mask = 0; mask <= all; mask++){
            if(dp[mask] >= INF) continue;
            for(register int i=0; i<n; i++){
                if(!(mask & bitmask[i])){
                    for(register int j=i+1; j<n; j++){
                        if(!(mask & bitmask[j]) && pass[i][j] && !(pass[i][j] & mask)){
                            dp[mask|pass[i][j]] = min(dp[mask] + 1, dp[mask|pass[i][j]]);
                        }
                    }
                    // dp[mask|mx[i]] = min(dp[mask|mx[i]], dp[mask]+1);
                    dp[mask|bitmask[i]] = min(dp[mask]+1, dp[mask|bitmask[i]]);
                    break;
                }
            }
        }
         
        cout << dp[all] <<"\n";
    }
}