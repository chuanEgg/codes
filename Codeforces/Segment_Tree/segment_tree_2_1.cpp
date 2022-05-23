#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int maxn = 1e5+5;
int s[maxn];
struct node
{
    int ans, l, r, sum;
    node(){}
    node(int a, int b, int c, int d){
        ans = a;
        l = b;
        r = c;
        sum = d;
    }
};
node tr[4*maxn];
node combine(node a, node b){
    node c;
    c.ans = max({a.ans, b.ans, a.r+b.l});
    c.l = max(a.sum+b.l, a.l);
    c.r = max(b.sum+a.r, b.r);
    c.sum = a.sum+b.sum;
    return c;
}
void build(int idx, int l, int r){
    if(l == r){
        tr[idx] = node(s[l],s[l],s[l],s[l]);
    }else{
        int m = (l+r)/2;
        build(idx*2+1, m+1, r);
        build(idx*2, l, m);
        tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
    }
}
void update(int pos, int idx, int l, int r, int val){
    if(l == r){
        tr[idx] = node(val,val,val,val);
        return;
    }
    int m = (l+r)/2;
    if(pos <= m){
        update(pos, idx*2, l, m, val);
    }else{
        update(pos, idx*2+1, m+1, r, val);
    }
    tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
}
// int query(int ql, int qr, int idx, int l, int r){
//     if(ql <= l && qr >= r){
//         return tr[idx];
//     }
//     int m = (l+r)/2;
//     if(ql > m){
//         return query(ql, qr, idx*2+1, m+1, r);
//     }
//     if(qr <= m){
//         return query(ql, qr, idx*2, l, m);
//     }
//     return combine(query(ql, qr, idx*2+1, m+1, r), query(ql, qr, idx*2, l, m));
// }
// int find(int x, int idx, int l, int r){
//     if(l == r){
//         return l;
//     }
//     int m = (l+r)/2;
//     if(tr[idx*2] >= x){
//         return find(x, idx*2, l, m);
//     }
//     return find(x-tr[idx*2], idx*2+1, m+1, r);
// }
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    build(1,0,n-1);
    cout<<max(0LL, tr[1].ans)<<"\n";
    while(m--){
        int i,v;
        cin>>i>>v;
        update(i,1,0,n-1,v);
        cout<<max(0LL, tr[1].ans)<<"\n";
    }
}