#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int maxn = 2e5+5;
int bit[maxn];

int query(int i){
    int res = 0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}
void update(int i, int val){
    while(i<maxn){
        bit[i]+=val;
        i+=i&(-i);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int s,e,t;
        cin>>s>>e>>t;
        update(s,t);
        update(e+1, -t);
    }
    priority_queue<int> t;
    priority_queue<int,vector<int>, greater<int>> w;
    for(int i=1; i<=n; i++){
        int in;
        cin>>in;
        t.push(in);
        w.push(query(i));
    }
    int ans = 0;
    while(!t.empty()){
        int a = t.top();
        int b = w.top();
        t.pop(); w.pop();
        ans += (a*b);
    }
    cout<<ans<<"\n";
}