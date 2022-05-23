#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string burger;
    cin >> burger;
    int n = burger.length();
    int nb=0, ns=0, nc=0;
    for(int i=0; i<n; i++){
        if(burger[i] == 'B'){
            nb++;
        }else if(burger[i] == 'S'){
            ns++;
        }else{
            nc++;
        }
    }
    int b, s, c, pb, ps, pc, ruble;
    cin >> b >> s >> c >> pb >> ps >> pc >> ruble;
    int l = 0, r = 1e13;
    while(l+1 < r){
        int m = (l+r)/2;
        int res = 0;
        res += max(m*nb-b, 0LL)*pb;
        res += max(m*ns-s, 0LL)*ps;
        res += max(m*nc-c, 0LL)*pc;
        if(ruble < res){
            r = m;
        }else{
            l = m;
        }
        // cout << m <<"\t"<<ruble<<"\t"<<res<<"\n";
    }
    cout << l <<"\n";
}