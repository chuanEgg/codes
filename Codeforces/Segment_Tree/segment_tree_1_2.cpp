#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 1e5+1;
int a[maxn], tr[maxn*4];

int combine(int a, int b){
    return min(a,b);
}
void build(int idx, int l, int r){
    if(l == r){
        tr[idx] = a[l];
    }
    else{
        int m = (l+r)/2;
        build(idx*2, l, m);
        build(idx*2+1, m+1, r);
        tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
    }
}
int query(int ql, int qr, int idx, int l, int r){
    if(ql <= l && qr >= r){
        return tr[idx];
    }
    int m = (l+r)/2;
    if(qr <= m){
        return query(ql,qr,idx*2,l,m);
    }
    if(ql > m){
        return query(ql,qr,idx*2+1,m+1,r);
    }
    return combine(query(ql,qr,idx*2,l,m), query(ql,qr,idx*2+1,m+1,r));
}
void update(int pos, int val, int idx, int l, int r){
    if(l==r){
        tr[idx] = val;
        return;
    }
    int m = (l+r)/2;
    if(pos <= m) update(pos, val, idx*2, l, m);
    else update(pos, val, idx*2+1, m+1, r);
    tr[idx] = combine(tr[idx*2],tr[idx*2+1]);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);
    while(m--){
        int o;
        cin>>o;
        if(o == 1){
            int i,v;
            cin>>i>>v;
            update(i,v,1,0,n-1);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<query(l,r-1,1,0,n-1)<<"\n";
        }
    }
}