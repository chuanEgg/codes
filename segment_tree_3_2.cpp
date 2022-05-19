#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;
int s[maxn], tr[maxn*4], tag[maxn*4];

int combine(int a, int b){
    return max(a,b);
}
// void build(int idx, int l, int r){
//     if(l == r){
//         tr[idx] = s[l];
//     }else{
//         int m = (l+r)/2;
//         build((idx<<1), l, m);
//         build((idx<<1)|1, m+1, r);
//         tr[idx] = combine(tr[(idx<<1)], tr[(idx<<1)|1]);
//     }
// }
void push(int idx){
    if(tag[idx]){
        tr[idx<<1] = max(tag[idx],tr[idx<<1]);
        tr[idx<<1|1] = max(tag[idx],tr[idx<<1|1]);
        tag[idx<<1] = max(tag[idx], tag[idx<<1]);
        tag[idx<<1|1] = max(tag[idx], tag[idx<<1|1]);
        tag[idx] = 0;
    }
}
void update(int ql, int qr, int idx, int l, int r, int val){
    if(l!=r) push(idx);
    if(ql <= l && qr >= r){
        tr[idx] = max(tr[idx], val);
        tag[idx] = max(tag[idx], val);
        return;
    }
    int m = (l+r)/2;
    if(qr > m) 
        update(ql, qr, (idx<<1|1), m+1, r, val);
    if(ql <= m)
        update(ql, qr, (idx<<1), l, m, val);
    tr[idx] = combine(tr[idx<<1|1], tr[idx<<1]);
}
int query(int ql, int qr, int idx, int l, int r){
    if(l!=r) push(idx);
    if(ql <= l && r <= qr){
        return tr[idx];
    }
    int m = (l+r)/2;
    if(ql > m){
        return query(ql, qr, idx<<1|1, m+1, r);
    }
    if(qr <= m){
        return query(ql, qr, idx<<1, l, m);
    }
    return combine(query(ql, qr, idx<<1|1, m+1, r), query(ql, qr, idx<<1, l, m));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int l, r, v;
            cin>>l>>r>>v;
            update(l,r-1,1,0,n-1,v);
        }else{
            int i;
            cin>>i;
            cout<<query(i, i,1,0,n-1)<<"\n";
        }
    }
}