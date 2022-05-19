#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int mod = 1e9+7;
int fastpow(int x, int t, int p){
    int res = 1;
    while(t > 0){
        if(t&1){
            res = res*x%p;
        }
        x = x*x%p;
        t>>=1;
    }
    return res%p;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, b;
        cin >> n>>k>>b;
        cout << fastpow(n,fastpow(k, b, mod-1), mod) << "\n";
    }
}