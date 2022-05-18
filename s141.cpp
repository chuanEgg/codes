#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;
int dp[maxn]{0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> s(n);
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++){
            cin >> s[i];
            dp[i] = s[i];
        }
        dp[2] += dp[0];
        for(int i=3; i<n; i++){
            dp[i] += max(dp[i-2], dp[i-3]);
        }
        dp[n] = max(dp[n-1], dp[n-2]);
        cout << dp[n] <<"\n";
    }
}