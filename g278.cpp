#include <vector>
#include <iostream>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e5+5;
int cnt[N];

signed main(){
    fastio
    int n,k, ans = 0;
    cin >> n >> k;
    vector<int> arr, left;
    arr.resize(n+1);
    left.resize(n+1);
    vector<vector<int>> dp, mx;
    dp.resize(n+1,vector<int>(k+1,0));
    mx.resize(n+1,vector<int>(k+1,0));
    for(int i = 1;i <= n;i++) cin >> arr[i];
    int l = n, r = n+1;
    while(l){
        while(r-1>=1&&cnt[arr[r-1]]==0) cnt[arr[r-1]]++, r--;
        cnt[arr[l]]--;
        left[l] = r;
        l--;
    }/* 
	for(int i=1; i<=n; i++){
		cout<<left[i]<<" ";
	}cout<<endl;*/
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k;j++){
            dp[i][j] = max(dp[i][j],mx[left[i]-1][j-1]+i-left[i]+1);
            ans = max(dp[i][j],ans);
            mx[i][j] = max(dp[i][j],mx[i-1][j]);
        }
    }

    cout << ans << "\n";

}