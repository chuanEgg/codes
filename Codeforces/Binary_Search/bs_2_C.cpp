#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int l = 0, r = n*max(x,y)+1;
    while(l < r){
        int m = (l+r)/2;
        if(m/x + m/y >= n-1){
            r = m;
        }else{
            l = m+1;
        }
    }
    cout << l+min(x,y) << "\n";
}