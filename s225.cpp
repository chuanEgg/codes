#pragma GCC optimize ("Ofast", "unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double delta = s[i].x * s[j].x * (s[i].x - s[j].x);
                double a = (s[j].x * s[i].y - s[i].x * s[j].y)/delta;
                double b = (s[i].x * s[i].x * s[j].y - s[j].x * s[j].x * s[i].y)/delta;
                if(delta == 0 || a >= 0) continue;
                for(int k = 0; k<n; k++){
                    if(abs(s[k].x * s[k].x * a + s[k].x * b - s[k].y) <= 1e-7){
                        pass[i][j] |= bitmask[k];
                    }
                }
                // if(__builtin_popcount(pass[i][j]) > __builtin_popcount(mx[i])){
                //     mx[i] = pass[i][j];
                // }
                // cout << i <<' '<<j<<' ' <<pass[{i, j}] <<'\n';
                // cout << a <<" "<< b<<'\n';
            }
        }

        int all = bitmask[n]-1;
        vector<int> dp(1<<n, INF);
        dp[0] = 0;
        
        for(int mask = 0; mask <= all; mask++){
            for(int i=0; i<n; i++){
                if(!(mask & bitmask[i])){
                    for(int j=i+1; j<n; j++){
                        if(!(mask & bitmask[j]) && pass[i][j] && !(pass[i][j] & mask)){
                            dp[mask|pass[i][j]] = min(dp[mask] + 1, dp[mask|pass[i][j]]);
                        }
                    }
                    // dp[mask|mx[i]] = min(dp[mask|mx[i]], dp[mask]+1);
                    dp[mask|bitmask[i]] = min(dp[mask]+1, dp[mask|bitmask[i]]);
                }
            }
        }
        cout << dp[all] <<"\n";
    }
}