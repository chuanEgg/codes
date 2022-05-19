#include <iostream>
#include <vector>
#include <cstring>
 
using namespace std;
 
const int mod = 1e9+7;
 
void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}
void sub_self(int& a, int b) {
    a -= b;
    if(a < 0) {
        a += mod;
    }
}
 
 
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> dp(k + 1);
    dp[0] = 1;
    for(int child = 0; child < n; ++child) {
        int up_to;
        scanf("%d", &up_to);
        vector<int> fake(k + 1);
        for(int used = k; used >= 0; --used) {
            int tmp = dp[used];
            int L = used + 1;
            int R = used + min(up_to, k - used);
            if(L <= R) {
                add_self(fake[L], tmp);
                if(R + 1 <= k) {
                    sub_self(fake[R+1], tmp);
                }
            }
            for(int i=0; i<=k; i++){
                cout<<fake[i]<<" ";
            }
            cout<<"\n";
        }
        int prefix_sum = 0;
        for(int i = 0; i <= k; ++i) {
            add_self(prefix_sum, fake[i]);
            add_self(dp[i], prefix_sum);
            cout<<dp[i]<<"\n";
        }//快速加法
        
    }
    printf("%d\n", dp[k]);
}