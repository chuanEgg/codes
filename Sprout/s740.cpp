#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 1e9+7, range = 1500;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(m, vector<int>(k));
    vector<vector<int>> c(n, vector<int>(k));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];
    for(int i=0; i<m; i++)
        for(int j=0; j<k; j++)
            cin >> b[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<k; j++)
            cin >> c[i][j];
    vector<int> r(k), resb(m), resc(n), res(n);
    for(int i=0; i<k; i++)
        r[i] = rng() % range;
    for(int i=0; i<m; i++){
        int temp = 0;
        for(int j=0; j<k; j++){
            temp += r[j]*b[i][j];
        }
        resb[i] = temp;
    }
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=0; j<k; j++){
            temp += r[j]*c[i][j];
        }
        resc[i] = temp;
    }
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=0; j<m; j++){
            temp += resb[j]*a[i][j];
        }
        res[i] = temp;
    }
    bool flag = 1;
    for(int i=0; i<n; i++){
        if(res[i] != resc[i]){
            flag = 0;
            break;
        }
    }
    cout << (flag?"Yes":"No") <<"\n";
}