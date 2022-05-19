#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string t,p;
    cin >> t >> p;
    int n = t.length();
    vector<int> s(n+1), check(n);
    // vector<vector<int>> q(n+1, vector<int>(n, 1));
    for(int i=1 ;i<=n; i++){
        cin >> s[i];
        s[i] --;
        check[s[i]] = i;
        // check[s[i]] = 0;
        // q[i] = check;
    }
    int l=0, r=n+1;
    while(l < r){
        int m=(l+r)/2;
        string res;
        for(int i=0; i<n; i++){
            // cout << check[i] <<(" \n"[i == n-1]);
            if(check[i] > m){
                res += t[i];
            }
        }
        bool pass = 1;
        // pass = 1 too less
        // pass = 0 too much
        int cur = 0;
        for(int i=0; i<res.length(); i++){
            if(res[i] == p[cur]){
                cur++;
            }
        }
        if(cur < p.length())
            pass = 0;
        // cout <<m <<"\t"<< res <<"\t"<<pass<<"\n";
        if(!pass){
            r = m;
        }else{
            l = m+1;
        }
    }
    l--;
    // string res;
    // for(int i=0; i<n; i++){
    //     // cout << q[m][i] <<"\n";
    //     if(q[l][i]){
    //         res += t[i];
    //     }
    // }
    // cout << res <<"\n";
    cout << l <<"\n";
}