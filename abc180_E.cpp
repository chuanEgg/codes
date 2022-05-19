#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 20, INF = 1e9;
struct S{
    int x, y, z;
}s[maxn];

int dis[maxn][maxn], bit[maxn], dp[maxn][1<<maxn];

int get_dis(int u, int v){
    return abs(s[u].x - s[v].x) + abs(s[u].y - s[v].y) + max(0, s[v].z - s[u].z);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i].x >> s[i].y >> s[i].z;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dis[i][j] = get_dis(i, j);
        }
    }
    bit[0] = 1;
    for(int i=1; i<=n; i++){
        bit[i] = bit[i-1]<<1;
    }
    int all = bit[n]-1;
    // int temp = all;
    // while(temp > 0){
    //     cout << temp%2;
    //     temp/=2;
    // }
    for(int i=1; i<=all; i++){
        for(int j=0; j<n; j++){
            dp[j][i] = INF;
        }
    }
    dp[0][1] = 0;
    for(int mask = 1; mask < all; mask++){
        for(int j=0; j<n; j++){
            if(mask & bit[j]){
                for(int k = 0; k<n; k++){
                    if(!(mask&bit[k])){
                        dp[k][mask|bit[k]] = min(dp[k][mask|bit[k]], dp[j][mask]+dis[j][k]);
                    }
                }
            }
        }
    }
    int ans = INF;
    for(int i=1; i<n; i++){
        ans = min(dp[i][all]+dis[i][0], ans);
    }
    cout << ans <<"\n";
}