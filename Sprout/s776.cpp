#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int unsigned long long
using namespace std;
 
vector<vector<int>> s;
int n,m,k;
const int mod = 1e9+7;
 
vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> res = a;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp = 0;
            for(int k = 0; k<n; k++){
                temp += (a[i][k]*b[k][j]%mod);
            }
            temp %= mod;
            //cout<<temp<<"\n";
            res[i][j] = temp;
        }
    }
    return res;
}
vector<vector<int>> p(vector<vector<int>> a,int t){
    if(t == 1) return a;
    if(t%2 == 0){
        vector<vector<int>> temp = p(a,t/2);
        return mult(temp,temp);
    }
    vector<vector<int>> temp = p(a,(t-1)/2);
    return mult(a,mult(temp,temp));
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>> n >> m >> k;
    int in;
    s.resize(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >>v;
        u--, v--;
        s[u][v] = 1;
    }
    int cnt = 0;
    auto ans = p(s,k);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << ans[i][j] <<(" \n"[j==n-1]);
        }
    }
}