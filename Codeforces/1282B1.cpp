#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 2e5+1;
int s[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,p,k,sum;
        cin>>n>>p>>k;
        for(int i=0; i<n; i++)
            cin>>s[i];
        sort(s,s+n);
        int temp = 0, ans = 0;
        for(int i=0; i<k; i++){
            if(temp>p)
                break;
            int sum = temp;
            int cnt = i;
            for(int j=i+k-1; j<n; j+=k){
                if(s[j]+sum<=p){
                    sum+=s[j];
                    cnt+=k;
                }else
                    break;
            }
            ans = max(ans,cnt);
            temp += s[i];
        }
        cout<<ans<<"\n";
    }
}