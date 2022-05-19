#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define all(x) x.begin(),x.end()
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double c;
    cin >> c;
    double l=1, r=1e22;
    while(l+1e-6<r){
        auto m=(l+r)/2;
        if(m*m + sqrt(m) >= c){
            r = m;
        }else{
            l = m;
        }
    }
    cout << fixed << setprecision(6)<< l<<"\n";
}