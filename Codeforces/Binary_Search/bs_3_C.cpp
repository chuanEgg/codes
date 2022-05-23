#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    int mn = 1e10;
    for(int i=0; i<n; i++){
        cin >> s[i];
        if(s[i])
            mn = min(mn, s[i]-s[i-1]);
    }
    int l = mn, r = s[n-1]-s[0]+1;
    while(l+1 < r){
        int m = (l+r)/2;
        int lst = 0, res = 0;
        for(int i=0; i<n; i++){
            if(s[i] - s[lst] >= m){
                lst = i;
                res ++;
            }
        }
        res += 1;
        if(res >= k){
            l = m;
        }else{
            r = m;
        }
    }
    cout << l <<"\n";
}