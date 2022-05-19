#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    for(int sum = 1; sum <= n; sum++){
        int m = 0, temp = sum;
        while(temp){
            m = max(m, temp%10);
            temp/=10;
        }
        dp[sum] = dp[max(sum-m,0)]+1;
    }
    cout<<dp[n]<<"\n";
}