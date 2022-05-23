#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

int n, m;
const int maxn = 1e5+5;
const int inf = 1e10;
int a[maxn], tr[maxn*4], cnt;

int combine(int a, int b){
    return min(a,b);
}
void build(int idx, int l, int r){
    if(l == r){
        tr[idx] = inf;
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
int find_p(int ql, int qr, int x, int idx, int l, int r){
    if(l > qr || r < ql) return 0;
    if(l == r){
        if(tr[idx] <= x){
            update(l, inf, 1, 0, n-1);
            return 1;
        }
    }
    int m = (l+r)/2;
    if(tr[idx] <= x){
        int res = 0;
        if(tr[idx*2] <= x){
            res += find_p(ql, qr, x, idx*2, l, m);
        }
        if(tr[idx*2+1] <= x){
            res += find_p(ql, qr, x, idx*2+1, m+1, r);
        }
        return res;
    }
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<int> s(n, inf);
    build(1,0,n-1);
    // fill(tr, tr+maxn, inf);
    // cout<<"ok\n";
    for(int i=0; i<m; i++){
        int op;
        cin>>op;
        if(op == 1){
            int i, h;
            cin>>i>>h;
            s[i] = h;
            update(i, h, 1, 0, n-1);
        }else{
            int l,r,p;
            cin>>l>>r>>p;
            cout<<find_p(l, r-1, p, 1, 0, n-1)<<"\n";
        }
        // cout<<i<<'\n';
    }
}