#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 1e5+5;
int arr[maxn];
struct node{
    int ans, l, r, sum;
    node(){}
    node(int a, int b, int c, int d){
        ans = a, l = b, r = c, sum = d;
    }
} tr[4 * maxn];

node combine(node a, node b){
    node c;
    c.ans = max({a.ans, b.ans, a.r + b.l});
    c.l = max(a.sum + b.l, a.l);
    c.r = max(b.r, b.sum + a.r);
    c.sum = a.sum + b.sum;
    return c;
}
void build(int l, int r, int idx){
    if(l == r){
        tr[idx] = node(arr[l], arr[l], arr[r], arr[l]);
        return;
    }else{
        int m = l + (r - l) / 2;
        build(l, m, idx << 1);
        build(m + 1, r, idx << 1 | 1);
        tr[idx] = combine(tr[idx << 1], tr[idx << 1 | 1]);
    }
}
node query(int ql, int qr, int l, int r, int idx){
    if(ql <= l && r <= qr)  
        return tr[idx];
    int m = l + (r - l) / 2;
    if(m < ql)
        return query(ql, qr, m + 1, r, idx << 1 | 1);
    if(m >= qr)
        return query(ql, qr, l, m, idx << 1);
    return combine(query(ql, qr, l, m, idx << 1), query(ql, qr, m + 1, r, idx << 1 | 1));
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(0, n - 1, 1);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        node res = query(l, r, 0, n - 1, 1);
        cout << ((res.ans < 0)? 0: res.ans) << "\n";
    }
}