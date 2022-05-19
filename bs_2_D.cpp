#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
 
#define int long long
using namespace std;
 
const int maxn = 1005;
int ans[maxn];
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> t(p), z(p), y(p);
    for(int i=0; i<p; i++){
        cin >> t[i] >> z[i] >> y[i];
    }
    int l=0, r=1e9;
    while(l < r){
        fill(ans, ans+p, 0);
        int m=(l+r)/2;
        int res = 0;
        for(int i=0; i<p; i++){
            int temp = (t[i]*z[i]+y[i]);
            ans[i] += m/temp * z[i];
            ans[i] += (m%temp>=z[i]*t[i] ? z[i] : m%temp/t[i]);
            res += ans[i];
        }
        // cout << "\t"<<res <<"\t"<<l<<"\t"<<r<<"\t"<<m<<"\n";
        for(int i=0; i<p; i++){
            if(res > n){
                int temp = min(res-n, ans[i]);
                ans[i] -= temp;
                res -= temp;
            }    
        }
        // cout << "\t" <<res <<"\n";
        if(res >= n){
            r = m;
        }else{
            l = m+1;
        }
    }
    cout << l<<"\n";
    fill(ans, ans+p, 0);
    int res = 0;
    for(int i=0; i<p; i++){
        int temp = (t[i]*z[i]+y[i]);
        ans[i] += l/temp * z[i];
        ans[i] += (l%temp>=z[i]*t[i] ? z[i] : l%temp/t[i]);
        res += ans[i];
    }
    // cout << "\t"<<res <<"\t"<<l<<"\t"<<r<<"\t"<<m<<"\n";
    for(int i=0; i<p; i++){
        if(res > n){
            int temp = min(res-n, ans[i]);
            ans[i] -= temp;
            res -= temp;
        }    
    }
    for(int i=0; i<p; i++){
        cout << (ans[i]) <<(" \n"[i == p-1]);
    }
}