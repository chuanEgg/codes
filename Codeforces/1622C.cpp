#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;

int f(int a, int b){
    int res = a/b;
    while(res*b > a)
        res--;
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k, sum = 0;
        cin>>n>>k;
        vector<int> s(n);
        vector<int> pre(n+1, 0);
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        sort(s.begin(), s.end());
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + s[i];
        }
        int ans = 1e18;
        for(int i=0; i<n; i++){
            int temp = s[0] - f((k-pre[n-i]+s[0]) ,(i+1));
            ans = min(ans, i+max(0LL, temp));
        }
        cout<<ans<<"\n";
    }
}