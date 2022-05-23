#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define int long long
#define INF 1e18
using namespace std;
typedef pair<int, int> P;
int s[101];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, h;
        cin >> n >> h;
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        s[n] = INF;
        int l = 0, r = h;
        while(r - l > 0){
            int m = l + (r - l) / 2, d = 0;
            for(int i = 0; i < n; i++){
                d += min(m, s[i + 1] - s[i]);
            }
            if(d < h) l = m + 1;
            else r = m;
        }
        cout << r << "\n";
    }
    return 0;
}