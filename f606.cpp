#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> v(n, vector<int>(m));
	for (auto& i : v) for (auto& j : i) cin >> j;
    int ans = 1e18;
    while(k--){
        int sum = 0;
        vector<int> cnt[m];
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            cnt[temp].push_back(i);
        }
        for(int i=0; i<m; i++){
            if(cnt[i].empty()) continue;
            for(int j=0; j<m; j++){
                int temp = 0;
                for(auto x:cnt[i])
                    temp+=v[x][j];
                    if(i == j){
                        sum += temp;
                    }else if(sum >= 1000)
                        sum += 3000 +(temp - 1000)*2;
                    else sum += temp*3;
            }
        }
        ans = min(ans, sum);
    }
    cout<<ans<<"\n";
}