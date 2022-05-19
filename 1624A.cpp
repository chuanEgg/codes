#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m=0, mini = 1e18;
        cin >> n;
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin >> s[i];
            m = max(s[i], m);
            mini = min(mini, s[i]);
        }
        cout << m-mini <<"\n";
    }
}