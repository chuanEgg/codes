#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), v(n);
    for(int i=0; i<n; i++){
        cin >> p[i] >> v[i];
    }
    double l=0, r=1e22;
    while(l+1e-6<r){
        double m = (l+r)/2;
        double yl = -1e18, yr = 1e18;
        for(int i=0; i<n; i++){
            yl = max(yl, p[i] - v[i]*m);
            yr = min(yr, p[i] + v[i]*m);
        }
        if(yl <= yr){
            r = m;
        }else{
            l = m;
        }
    }
    cout <<fixed << setprecision(6)<< l <<"\n";
}