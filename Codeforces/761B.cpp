#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define int long long
using namespace std;
typedef pair<int, int> P;
void solve(){
    int n;
    cin >> n;
    if(n % 2){
        for(int i = 3, j = n - 4; i < j; i += 2, j -= 2){
            if(__gcd(i, j) == 1){
                cout << i << " " << j << " 1\n";
                return;
            }
        }
    }
    else{
        for(int i = 2, j = n - 3; i < j; i++, j--){
            if(__gcd(i, j) == 1){
                cout << i << " " << j << " 1\n";
                return;
            }
        }
    }
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}