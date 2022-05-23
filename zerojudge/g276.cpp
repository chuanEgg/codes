#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#define int long long
using namespace std;
struct king{
    int r, c, s, t;
};
king a[501];
int mp[101][101], cnt, ans = 0;
vector<int> pos[101][101];
bool gone[501];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) cin >> a[i].r >> a[i].c >> a[i].s >> a[i].t;
    cnt = k;
    memset(gone, 0, sizeof(gone));
    memset(mp, 0, sizeof(mp));
    while(cnt){
        for(int i = 0; i < k; i++){
            if(gone[i]) continue;
            mp[a[i].r][a[i].c]++;
            if(a[i].r + a[i].s < 0 || a[i].r + a[i].s >= n ||
             a[i].c + a[i].t < 0 || a[i].c + a[i].t >= m){
                gone[i] = 1;
                cnt--;
                continue;
            }
            a[i].r += a[i].s;
            a[i].c += a[i].t;
            pos[a[i].r][a[i].c].push_back(i);
            // cout << i << " " << a[i].r << " " << a[i].c << "\n";
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mp[i][j] && pos[i][j].size()){
                    mp[i][j] = 0;
                    for(int l: pos[i][j]){
                        gone[l] = 1;
                        cnt--;
                    }
                }
                pos[i][j].clear();
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j]) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}