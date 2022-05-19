#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int maxn = 4e5+1;
int s[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        memset(s,0,sizeof(s));
        for(int i=0; i<k; i++){
            cin>>s[i];
        }
        sort(s,s+k);
        int sum = 0, cnt=0;
        for(int i=k-1; i>=0; i--){
            sum+=(n-s[i]);
            //cout<<"\t"<<sum<<"\n";
            if(sum<n){
                cnt++;
            }else{
                break;
            }
        }
        cout<<cnt<<"\n";
    }
}