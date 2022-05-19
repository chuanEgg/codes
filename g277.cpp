#include <iostream>
#include <algorithm>

using namespace std;
#define int long long
const int maxn = 3e5+1;
int sum[maxn];
pair<int,int> s[maxn];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>s[i].first;
        sum[i] = sum[i-1]+s[i].first;
        s[i].second=i;
        //cout<<sum[i]<<" ";
    }
    sort(s+1,s+n);/*
    for(int i=1; i<=n; i++){
        cout<<s[i].first<<" "<<s[i].second<<"\n";
    }
    cout<<"\n";*/
    int l=1, r=n;
    int cnt =1;
    while(l!=r){
        pair<int,int> m=s[cnt];
        while(m.second < l || m.second > r){
            m=s[++cnt];
        }
        //cout<<m.first<<"\n";
        int ls = sum[m.second-1] - sum[l-1];
        int rs = sum[r] - sum[m.second];
        //cout<<ls<<" "<<rs<<"\n";
        if(ls>rs){
            r=(m.second-1);
        }else{
            l=m.second+1;
        }
        //cout<<l<<"\t"<<r<<"\n";
        //break;
    }
    cout<<sum[l]-sum[l-1];
}