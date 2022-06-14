#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+5;
int bitmask[maxn];

void trans(int temp){
    while(temp > 0){
        cout << temp % 2;
        temp /= 2;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bitmask[0] = 1;
    for(int i=1; i<maxn; i++)
        bitmask[i] = (bitmask[i-1]<<1);

    vector<vector<int>> c(n, vector<int>(m));
    vector<int> temp(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> c[i][j];
            temp[i] += (((c[i][j])%2) << (m-j-1));
        }
    }
    // for(int i=0; i<n; i++){
    //     cout << std::bitset<32>(temp[i]);
    //     cout <<"\n";
    // }
    // cout << std::bitset<32>((1<<m)-1);
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((temp[i] ^ temp[j]) !=(1<<m)-1){
                ans += 1;
            }
        }
    }
    cout << ans <<"\n";
}