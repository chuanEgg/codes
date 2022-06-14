#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    double l = 0, r = 1e14;
    for(int i=0; i<100; i++){
        double m = (l+r)/2;

    }
}
/*
5 3
4 4
3 2
2 3
1 5
*/