#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 1e5+5;
int s[maxn], tag_assign[4*maxn], tag_add[4*maxn], tr[4*maxn];

int combine(int a, int b){
    return a+b;
}
void build(int idx, int l, int r)
{
    if(l == r){
        tr[idx] = s[l];
    }else{
        int m = (l+r)/2;
        build(idx<<1, l, m);
        build(idx<<1|1, m+1, r);
        tr[idx] = combine(tr[idx<<1], tr[idx<<1|1]);
    }
}
void push(int idx, int l, int r){
    int m = (l+r)/2;
    if(tag_assign[idx]!=-1){
        tr[idx<<1] = tag_assign[idx]*(m-l+1);
        tr[idx<<1|1] = tag_assign[idx]*(r-m);
        tag_assign[idx<<1|1] = tag_assign[idx];
        tag_assign[idx<<1] = tag_assign[idx];
        tag_add[idx<<1] = tag_add[idx<<1|1] = 0;
        tag_assign[idx] = -1;
    }
    
    if(tag_add[idx]){
        tr[idx<<1] += tag_add[idx]*(m-l+1);
        tr[idx<<1|1] += tag_add[idx]*(r-m);
        tag_add[idx<<1] += tag_add[idx];
        tag_add[idx<<1|1] += tag_add[idx];
        tag_add[idx] = 0;
    }
}
void add(int ql, int qr, int val, int idx, int l, int r){
    if(l!=r) push(idx,l,r);
    if(ql <= l && r<= qr){
        tr[idx] += val*(r-l+1);
        tag_add[idx] += val;
        return;
    }
    int m = (l+r)/2;
    if(qr > m)
        add(ql,qr,val,idx*2+1,m+1,r);
    if(ql <= m)
        add(ql,qr,val,idx*2, l,m);
    tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
}
void assign(int ql, int qr, int val, int idx, int l,int r){
    if(l!=r) push(idx,l,r);
    if(ql <= l && r<= qr){
        tr[idx] = val*(r-l+1);
        tag_assign[idx] = val;
        tag_add[idx] = 0;
        return;
    }
    int m = (l+r)/2;
    if(qr > m)
        assign(ql,qr,val,idx*2+1,m+1,r);
    if(ql <= m)
        assign(ql,qr,val,idx*2, l,m);
    tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
}
int query(int ql, int qr, int idx, int l, int r){
    if(l!=r) push(idx,l,r);
    if(ql <= l && r<=qr){
        return tr[idx];
    }
    int m=(l+r)/2;
    if(ql>m)
        return query(ql,qr,idx*2+1,m+1,r);
    if(qr<=m)
        return query(ql,qr,idx*2,l,m);
    return combine(query(ql,qr,idx*2+1,m+1,r),query(ql,qr,idx*2,l,m));
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill(tag_assign, tag_assign+(4*maxn), -1);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int op;
        cin>>op;
        if(op == 1){
            int l,r,v;
            cin>>l>>r>>v;
            assign(l,r-1,v,1,0,n-1);
        }else if(op == 2){
            int l,r,v;
            cin>>l>>r>>v;
            add(l,r-1,v,1,0,n-1);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<query(l,r-1,1,0,n-1)<<"\n";
        }
    }
}