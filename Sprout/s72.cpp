#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

double func(double a, double b, double c, double t){
    return a*(t-b)*(t-b)+c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<double> a(n), b(n), c(n);
        for(int i=0; i<n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        double l = 0, r = 300;
        while(l+1e-6 < r){
            double m = (l+r)/2;
            double res1 = 0, res2 = 0;
            for(int i=0; i<n; i++){
                res1 = max(func(a[i],b[i],c[i], m), res1);
                res2 = max(func(a[i],b[i],c[i], m+1e-6), res2);
            }
            // cout << fixed<<setprecision(10) << res1 << "\t" << res2 <<"\n";
            if(res1 < res2){
                r = m;
            }else{
                l = m;
            }
        }
        double ans = 0;
        for(int i=0; i<n; i++){
            ans = max(func(a[i],b[i],c[i], l), ans);
        }
        cout << fixed << setprecision(10) << ans <<"\n";
    }
}