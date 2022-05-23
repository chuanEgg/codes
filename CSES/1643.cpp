#include <iostream>
#include <sstream>
#define int long long

using namespace std;
int n;
const int maxn = 2e5+1;
const int INF = -2e15;
int s[maxn],dp[maxn],ans;
signed main() {
	n = 1;
	while(n--){
		int k;
		cin>>k;
		ans=0;
		for(int i=0; i<k; i++){
			cin>>s[i];
		}
		dp[0]=s[0];
		int ans=INF;
		if(k==1){
			cout<<s[0]<<endl;
			break;
		} 
		for(int i=1; i<k; i++){
			dp[i]=max(dp[i-1]+s[i],s[i]);
			ans=max(ans,dp[i]);
			//cout<<dp[i]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}