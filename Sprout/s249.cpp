#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

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
        return;
    }else{
        int m = (l+r)/2;
        build(idx*2+1, m+1, r);
        build(idx*2, l, m);
        tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
    }
}
node query(int ql, int qr, int idx, int l, int r){
    if(ql <= l && qr >= r){
        return tr[idx];
    }
    int m = (l+r)/2;
    if(ql > m){
        return query(ql, qr, idx*2+1, m+1, r);
    }
    if(qr <= m){
        return query(ql, qr, idx*2, l, m);
    }
    return combine(query(ql, qr, idx*2, l, m),query(ql, qr, idx*2+1, m+1, r));
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    build(1,0,n-1);
    while(m--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        node res = query(l, r, 1, 0, n-1);
        cout << ((res.ans<0)?0:res.ans) <<"\n";
    }
}