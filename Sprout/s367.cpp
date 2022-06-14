#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 1e5+5;
int tr[maxn * 4], arr[maxn], tag[maxn * 4];

int combine(int a, int b){
    return max(a, b);
}
void build(int idx, int l, int r){
    if(l == r){
        tr[idx] = arr[l];
    }else{
        int m = (l+r)/2;
        build(idx<<1, l, m);
        build(idx<<1|1, m+1, r);
        tr[idx] = combine(tr[idx<<1], tr[idx<<1|1]);
    }
}
void push(int idx){
    if(tag[idx]){
        tr[idx<<1] += tag[idx];
        tr[idx<<1|1] += tag[idx];
        tag[idx<<1] += tag[idx];
        tag[idx<<1|1] += tag[idx];
        tag[idx] = 0;
    }
}
void modify(int ql, int qr, int val, int idx, int l, int r){
    if(l!=r)    push(idx);
    if(ql <= l && r <= qr){
        tr[idx] += val;
        tag[idx] += val;
        return;
    }
    int m = (l+r)/2;
    if(qr > m) 
        modify(ql, qr, val, idx<<1|1, m+1, r);
    if(ql <= m)
        modify(ql, qr, val, idx<<1, l, m);
    tr[idx] = combine(tr[idx<<1], tr[idx<<1|1]);
}
int query(int ql, int qr, int idx, int l, int r){
    if(l!=r)    push(idx);
    if(ql <= l && r <= qr){
        return tr[idx];
    }
    int m = (l+r)/2;
    if(ql > m)
        return query(ql, qr, idx<<1|1, m+1, r);
    if(qr <= m)
        return query(ql, qr, idx<<1, l, m);
    return combine(query(ql, qr, idx<<1, l, m), query(ql, qr, idx<<1|1, m+1, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    while(m--){
        int o;
        cin >> o;
        if(o == 1){
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            modify(l, r, x, 1, 0, n-1);
        }else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(l, r, 1, 0, n-1) <<'\n';
        }
    }
}