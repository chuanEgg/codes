#include <iostream>

using namespace std;

const int maxn = 1e5+1;
long long s[maxn], sum[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin>>n>>p;
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>s[i];
        s[i]%=p;
        sum[i] = sum[i-1] +s[i];
    }
    int ans = 0;
    for(int i=1; i<n; i++){
        int l = sum[i];
        int r = sum[n] - sum[i];
        l%=p;
        r%=p;
        ans = max(l+r, ans);
    }
    cout<<ans<<"\n";
}