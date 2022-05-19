#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int mod = 1e9+7;
int fastpow(int x, int t){
    int res = 1;
    while(t > 0){
        if(t&1){
            res = res*x%mod;
        }
        x = x*x % mod;
        t>>=1;
    }
    return res%mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, b;
        cin >> n>>k;
        cout << fastpow(n, k) << "\n";
    }
}