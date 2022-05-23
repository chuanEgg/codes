#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma")
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


const int mxn = 2e5 + 1;
int n, arr[mxn], cnt, l;
bitset<1000001> b;
bool cmp(int a, int b) {return a > b;}
void solve(void) {
    cin >> n;
    b.reset();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        b[arr[i]] = 1;
    }
    sort(arr, arr + n, cmp);
    cnt = 0;
    l = n >> 1;
    for (int i = 0; i < n/2; i++) {
        for (int j = n/2; j < n; j++) {
            if (arr[i] == arr[j]) continue;
            if (b[arr[i] % arr[j]] == 0) {
                cout << arr[i] << ' ' << arr[j] << '\n';
                ++cnt;
                if (cnt == l) return;
            }
        }
    }
}


signed main(void){
    
    int t;
    fio
    cin >> t;
    while (t--) {
        solve();
    }
}
