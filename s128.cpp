/*
X =>
X   X+N (diag-1)
X+N X
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024;
vector<vector<int>> base(1, vector<int>(1,1));

void Report(int n){
    cout << n <<"\n";
}
vector<vector<int>> cut(int n){
    if(n == 1) return base;
    auto a = cut(n/2);
    auto res = a;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            int push = (i == j? (a[i][j]+n-1):(a[i][j]+n));
            res[i].push_back(push);
        }
        res.push_back(vector<int>(1, a[i][0]+n));
    }
    for(int i = n/2; i<n; i++){
        for(int j = 1; j<n/2; j++){
            res[i].push_back(a[i-(n/2)][j]+n);
        }
    }
    for(int i=n/2; i<n; i++){
        for(int j=n/2; j<n; j++){
            res[i].push_back(a[i-n/2][j-n/2]);
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << res[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }
    return res;
}
void solve(int n){
    auto ans = cut(n);
    for(int i=0; i<n*n; i++){
        Report(int(ans[i/n][i%n]));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
}