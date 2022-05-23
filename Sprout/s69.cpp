#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int INF = 1e17;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> s(n), g(n), e(n), now(n);
        for(int i = 0; i<n; i++){
            cin >> s[i] >> g[i];
        }
        for(int i = 0; i<n; i++){
            cin >> e[i];
        }
        sort(e.begin(), e.end());
        int l = -1, r = 1e17;
        while(l+1 < r){
            int m = (l+r)/2;
            int res = 0;
            for(int i = 0; i<n; i++){
                now[i] = s[i]+g[i]*m;
            }
            sort(now.begin(), now.end());
            for(int i = 0; i<n; i++){
                if(now[i] > e[res]){
                    res++;
                }
                if(res >= k) break;
            }
            // cout << res <<"\t"<<m<<"\n";
            if(res < k || m < 0){
                l = m;
            }else{
                r = m;
            }
        }
        cout << ((r >= INF)?-1:r)<<"\n";
    }
}