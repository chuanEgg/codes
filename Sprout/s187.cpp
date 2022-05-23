#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 18, INF = 1e9;
int dis[maxn][maxn], bitmask[maxn], dp[maxn][1<<maxn];

void trans(int temp){
    while(temp > 0){
        cout << temp % 2;
        temp /= 2;
    }
}
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
        int all = bitmask[n]-1;
        for(int i=0; i<n; i++){
            for(int j=1; i+j<n; j++){
                int temp;
                cin >> temp;
                dis[i][i+j] = temp;
                dis[i+j][i] = temp;
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++)
        //         cout << dis[i][j] <<" ";
        //     cout <<"\n";
        // }
        // cout << all <<"\n";
        for(int i=1; i<=all; i++){
            for(int j=0; j<n; j++){
                dp[j][i] = INF;
            }
        }
        dp[0][1] = 0;
        for(int mask = 1; mask < all; mask++){
            for(int j=0; j<n; j++){
                if(mask & bitmask[j]){
                    for(int k=0; k<n; k++){
                        if(!(mask & bitmask[k])){
                            dp[k][mask|bitmask[k]] = min(dp[k][mask|bitmask[k]], dp[j][mask] + dis[j][k]);
                            // cout << j << " " << k <<" ";
                            // trans(mask|bitmask[k]);
                            // cout<<" "<<dp[k][mask|bitmask[k]]<<"\n";
                        }
                    }
                }
            }
        }
        int ans = INF;
        for(int i=1; i<n; i++){
            ans = min(dp[i][all] + dis[i][0], ans);
            // cout <<i <<" "<< dp[i][all] <<"\n";
        }
        cout << ans <<"\n";
    }
}