#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;

const int maxk = 2e5+5;
const int INF = 0x3f3f3f3f3f3f3f3f;
// int dp[maxk][7];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // memset(dp,0x3f,sizeof(dp));
    int n,m,k;
    cin>>m>>n>>k;
    vector<int> s(k);
    // for(int i=1; i<=6; i++) dp[0][i] = 0;
    // s[0] = 0;
    bool flag = 0;
    for(int i=0; i<k; i++){
        int x,y;
        cin>>y>>x;
        int p = (y-1)*n;
        p+=((y%2 == 0)?(n-x+1):x);
        // cout<<p<<"\n";
        if(p == n*m){
            flag = 1;
        }
        s[i] = p;
    }
    sort(s.begin(), s.end());
    int ans = 0, pos = 0, lpos = 0;
    for(int i=0; i<k; i++){
        //cout<<s[i]<<"\n";
        if(s[i]%6 == pos%6){
            ans += (s[i]-pos+5)/6;
            lpos = pos;
            pos = s[i]-1;
            for(int j=1; j<=6 && (i-j)>=0; j++){
                if(s[i-j] < pos){
                    break;
                }else if(s[i-j] == pos){
                    pos--;
                }
            }
            if((((i-7)>=0) && pos==s[i-7])|| pos == lpos){
                flag = 1;
                break;
            }
            //cout<<pos<<"\t"<<s[i]<<"\n";
        }
        if(flag) break;
    }
    ans += ((n*m)-pos+5)/6;
    ans = (flag?-1:ans);
    cout<<ans<<"\n";
}