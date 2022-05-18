#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int maxn = 1e2+5, mod = 1000007;
int c[maxn][maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    c[0][0] = 1;
    for(int i=1; i<maxn; i++){
        for(int j=0; j<maxn; j++){
            if(j == 0){
                c[i][j] = c[i-1][j];
            }else{
                c[i][j] = c[i-1][j] + c[i-1][j-1];
            }
            c[i][j] %= mod;
        }
    }
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> s(n);
        for(int &i:s)
            cin >> i;
        int ans = 0;
        for(int i = 0; i<m; i++){
            long long temp = 1;
            for(int k:s){
                temp *= c[m-i][k];
                temp %= mod;
                // cout << c[n-i][k] <<"\t";
            }
            // cout << temp <<"\n";
            ans = ((i&1)?ans-temp*c[m][m-i] : ans+temp*c[m][m-i]);
            ans = (ans%mod+mod)%mod;
        }
        cout << ans <<"\n";
    }
}