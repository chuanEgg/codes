#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 2e5+5;
vector<pair<int,int>> q[maxn];
int s[maxn];
int bit[maxn];
int ans[maxn];

void update(int x, int val){
    while(x<maxn){
        bit[x] += val;
        x+=x&(-x);
    }
}
int query(int x){
    int res = 0;
    while(x>0){
        res+=bit[x];
        x-=x&(-x);
    }
    return res;
}
bool cmp(int a, int b){
    return a<b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>s[i];
        // update(i,1);
    }
    //vector<int> left(m);
    for(int i=0; i<m; i++){
        int l,r;
        cin>>l>>r;
        q[l].push_back({r,i});
        //left[i] = l;
    }
    //sort(left.begin(), left.end(), cmp);
    // for(int i=0; i<m; i++){
    //     cout<<q[i].first<<" "<<q[i].second<<"\n";
    // }
    map<int,int> exist;
    for(int i=n; i>=1; i--){
        int temp = s[i];
        if(exist.count(temp)){
            update(exist[temp], -1);
        }
        exist[temp] =i;
        update(i,1);
        for(auto j:q[i]){
            ans[j.second] = query(j.first);
        }
    }
    for(int i=0; i<m; i++){
        cout<<ans[i]<<"\n";
    }
}