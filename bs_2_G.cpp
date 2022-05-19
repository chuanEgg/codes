#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
 
#define int long long
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    vector<int> s(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> s[i];
        sum += s[i];
    }
    int l = 0, r = sum/k+1;
    while(l+1 < r){
        int m = (l+r)/2;
        // vector<int> c(m);
        int cur = 0, res = 0;
        for(int i=0; i<n; i++){
            // res += max({0LL, s[i]-m, s[i]-m*k+cur});
            cur += min(s[i], m);
            // cout << cur <<(" \n"[i == n-1]);
        }
        // cout << m <<"\t"<<cur<<"\t"<<m*k<<"\t"<<l<<"\t"<<r<<"\n";
        if(cur/m >= k){
            l = m;
        }else{
            r = m;
        }
    }
    cout << l <<"\n";
}
