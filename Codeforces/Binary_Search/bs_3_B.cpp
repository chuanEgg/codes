#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, mx = 0, sum = 0;
    cin >> n >> k;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        mx = max(mx, s[i]);
        sum += s[i];
    }
    int l = mx, r = sum+1;
    while(l<r){
        int m = (l+r)/2;
        int cur = 0, temp = 0;
        sum = 0;
        // cout <<"\n"<< m <<"\n";
        for(int i=0; i<n; i++){
            if(sum + s[i] <= m){
                sum+=s[i];
            }else{
                sum = s[i];
                cur ++;
                // cout << i<<" ";
            }
        }
        cur++;
        // cout <<"\n"<<m<<"\t"<< cur <<"\t"<<l<<"\t"<<r<<"\n";
        if(cur <= k){
            r = m;
        }else{
            l = m+1;
        }
    }
    cout << l<<"\n";
}