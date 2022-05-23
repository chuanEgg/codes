#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5+5;
vector<pair<int,int>> Q[maxn];
int ans[maxn], s[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        Q[l].push_back({r,i});
    }
    for(int i=n; i>=1; i--){
        
    }
}