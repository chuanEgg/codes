#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

const int maxn = 1e5+1;
int n,q;
set<int> st; //可能的解
vector<int> s,sum;

void solve(int l, int r){
    //cout<<l<<" "<<r<<"\n";
    st.insert(sum[r]-sum[l-1]);
    if(r-l<=0) return;
    int m = upper_bound(s.begin()+l, s.begin()+r+1, (s[l]+s[r])/2)-s.begin();
    if(s[l]==s[r]) return;
    solve(l,m-1);
    solve(m,r);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    s.resize(n+1);
    sum.resize(n+1);
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    sort(s.begin()+1, s.end());
    /*for(int i=0; i<=n; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;*/
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1]+s[i];
    }
    solve(1,n);
    while(q--){
        int temp;
        cin>>temp;
        cout<<(st.count(temp)?"Yes\n":"No\n");
    }
}