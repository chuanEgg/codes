#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


const int mxn = 2e5 + 1;
int n, arr[mxn], cnt, l;
bitset<1000001> b;
bool cmp(int a, int b) {
    if(a > b){
        if (b[arr[i] % arr[j]] == 0) {
            cout << arr[i] << ' ' << arr[j] << '\n';
            ++cnt;
            if (cnt == l) return;
        }
    }
    return a > b;
}
void solve(void) {
    cin >> n;
    b.reset();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        b[arr[i]] = 1;
    }
    cnt = 0;
    l = n >> 1;
    sort(arr, arr + n, cmp);
}


signed main(void){
    int t;
    fio
    cin >> t;
    while (t--) {
        solve();
    }
}