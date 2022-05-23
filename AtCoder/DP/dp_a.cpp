#include <iostream>
#include <cmath>

using namespace std;

const int maxn = 1e5+1;
int s[maxn];
int dp[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    dp[1] = abs(s[1]-s[0]);
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1]+abs(s[i-1]-s[i]), dp[i-2]+abs(s[i-2]-s[i]));
    }
    cout<<dp[n-1]<<"\n";
}