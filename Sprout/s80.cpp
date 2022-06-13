#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+5;
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
    cin>>m>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);
    while(m--){
        int o;
        cin>>o;
        if(o == 2){
            int i,v;
            cin>>i>>v;
            update(i,v,1,0,n-1);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<query(l,r,1,0,n-1)<<"\n";
        }
    }
}