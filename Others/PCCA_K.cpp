#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int fastpow(int n, int p){
    int res = 1;
    while(p){
        if(p&1){
            res = res*n;
        }
        n = n*n;
        p/=2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,p;
        cin >> n>>p;
        p--;
        int cnt = 0;
        while(!(p%2)){
            cnt++;
            p/=2;
        }
        // cout << cnt <<"\t" << fastpow(2,cnt)<<"\n";
        if(n < fastpow(2,cnt)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}