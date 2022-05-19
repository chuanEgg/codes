#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 2e5+5;
int bit[maxn];
int query(int i){
    int res = 0;
    while(i){
        res = max(res, bit[i]);
        i-=i&(-i);
    }
    return res;
}
void update(int i, int val){
    while(i<maxn){
        bit[i] = max(bit[i], val);
        i+=i&(-i);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> h(n), a(n);
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    for(int i=0; i<n; i++){
        cin>>a[i];
        update(h[i], query(h[i])+a[i]);
    }
    cout<<query(n)<<"\n";
}