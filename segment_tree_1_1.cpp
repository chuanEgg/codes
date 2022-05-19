#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 1e6+6;
int bit[maxn];
int query(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= i&(-i);
    }
    return res;
}
void update(int i, int val){
    while(i<maxn){
        bit[i] += val;
        i += i&(-i);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=1; i<=n; i++){
        cin>>v[i];
        update(i,v[i]);
    }
    while(m--){
        int o,i,j;
        cin>>o>>i>>j;
        if(o == 1){
            i++;
            update(i,-1*v[i]);
            v[i] = j;
            update(i,v[i]);
        }else{
            cout<<query(j)-query(i)<<"\n";
        }
    }
}