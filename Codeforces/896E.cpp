#pragma GCC optimize ("Ofast", "unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> s(n+1);
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    while(m--){
        int op, l, r, x;
        cin >> op>>l>>r>>x;
        if(op == 1){
            for(int i=l; i<=r; i++){
                if(s[i] > x){
                    s[i] -= x;
                }
            }
        }else{
            int res = 0;
            for(int i=l; i<=r; i++){
                if(s[i] == x){
                    res++;
                }
            }
            cout << res <<"\n";
        }
    }
}