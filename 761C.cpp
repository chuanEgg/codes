#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define int long long

using namespace std;

const int N = 2e5+5;
bool used[N];
int a[N], sum[N];

void solve(){
    int n, temp;
    cin >> n;
    memset(used, 0, sizeof(used));
    memset(a, 0, sizeof(a));
    sum[n + 1] = 0;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp > n || used[temp]){
            a[min((temp - 1) / 2, n)]++;
        }
        else used[temp] = 1;
    }
    for(int i = n; i >= 1; i--) sum[i] = sum[i + 1] + a[i];
    int time = 0;
    for(int i = n; i >= 1; i--){
        if(used[i]) continue;
        if(sum[i] > time){
            time++;
        }
        else{
            cout << "-1\n";
            return;
        }
    }
    cout << time << "\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}