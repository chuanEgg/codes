#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
// #define int long long
using namespace std;
typedef pair<int, int> P;
char s[1000001];
int n, t;
void solve(){
    cin >> n >> s;
    int ans = 8;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' && i + 1 < n){
            if(s[i + 1] == 'a'){
                ans = min(ans, 2);
            }
            else if(i + 2 < n){
                if((s[i + 1] == 'b' || s[i + 1] == 'c') && s[i + 2] == 'a'){
                    ans = min(3, ans);
                }
                else if(i + 3 < n){
                    if(((s[i + 1] == 'b' && s[i + 2] == 'c') || (s[i + 1] == 'c' && s[i + 2] == 'b')) && s[i + 3] == 'a'){
                        ans = min(4, ans);
                    }
                    else if(i + 6 < n && ((s[i + 1] == 'b' && s[i + 2] == 'b' && s[i + 3] == 'a' && s[i + 4] == 'c' && s[i + 5] == 'c' && s[i + 6] == 'a')
                    || (s[i + 1] == 'c' && s[i + 2] == 'c' && s[i + 3] == 'a' && s[i + 4] == 'b' && s[i + 5] == 'b' && s[i + 6] == 'a'))) ans = min(7, ans);
                }
            }
        }
    }
    if(ans != 8) cout << ans << "\n";
    else cout << "-1\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}