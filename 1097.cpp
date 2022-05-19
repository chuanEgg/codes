#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 5e3+5;
int dp[maxn][maxn];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, sum = 0;
    cin>>n;
    vector<int> s(n);
    for(int& i:s){
        cin>>i;
        sum += i;
    }
    for(int l=n-1; l>=0; l--){
        for(int r=l; r<n; r++){
            if(l == r){
                dp[l][r] = s[l];
            }else{
                dp[l][r] = max(s[l]-dp[l+1][r], s[r]-dp[l][r-1]);
            }
        }
    }
    cout<<(sum+dp[0][n-1])/2<<"\n";
}