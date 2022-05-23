#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e3+5;
int dp[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> s(n);
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++){
            cin >> s[i];
            dp[i] = s[i];
        }
        for(int i=k; i<2*k-1 && i<n; i++){
            int temp = 0;
            for(int j=k; j<=i; j++){
                temp = max(dp[i-j], temp);
            }
            dp[i] += temp;
            // cout << i <<" "<<temp<<"\n";
        }
        for(int i=2*k-1; i<n; i++){
            int temp = 0;
            for(int j=k; j<2*k; j++){
                temp = max(dp[i-j], temp);
            }
            dp[i] += temp;
        }
        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = max(ans, dp[n-i]);
        }
        cout << ans <<"\n";
    }
}