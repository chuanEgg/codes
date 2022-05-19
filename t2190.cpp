#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

int mod, a, b, x1, y1, x2, y2;
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
        cin >> mod >> a >> b >> x1 >> y1 >> x2 >> y2;
        int m = ((y2-y1)*fastpow(x2-x1, mod-2)) % mod;
        int x3 = (m*m % mod-x1-x2);
        x3 = (x3%mod + mod)%mod;
        int y3 = -1*((y1-y2)*(x2-x3) % mod )*fastpow(x1-x2, mod-2) + y2 % mod;
        y3 = (y3%mod + mod)%mod;
        cout << x3 <<" "<<y3<<"\n";
    }
}