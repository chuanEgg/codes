#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

int n, q, cur = 1;
const int maxn = 2e5+5;
const int inf = 1e18;
struct node{
    int left, right, sum;
} tr[maxn<<6];
vector<int> ver;

void update(int &root, int pos, int val, int l, int r){
    tr[cur].left = tr[root].left;
    tr[cur].right = tr[root].right;
    tr[cur].sum = tr[root].sum + val;
    root = cur;
    cur++;
    int mid = (l+r)/2;
    if(l == r){
        return;
    }
    if(pos <= mid){
        update(tr[root].left, pos, val, l, mid);
    }else{
        update(tr[root].right, pos, val, mid+1, r);
    }
}
int query(int root, int ql, int qr, int l, int r){
    if(ql <= l && r <= qr){
        return tr[root].sum;
    }
    int mid = (l+r)/2;
    int res = 0;
    if(ql<=mid)
        res += query(tr[root].left, ql, qr, l, mid);
    if(mid<qr)
        res += query(tr[root].right, ql, qr, mid+1, r);
    return res;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    ver.push_back(0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        update(ver[0], i, temp, 0, n-1);
    }
    while(q--){
        int op;
        cin>>op;
        if(op == 1){
            int k,a,x;
            cin>>k>>a>>x;
            k--; a--;
            update(ver[k], a, x-query(ver[k], a, a, 0, n-1), 0, n-1);
        }else if(op == 2){
            int k,a,b;
            cin>>k>>a>>b;
            k--; a--; b--;
            cout<<query(ver[k], a, b, 0, n-1)<<"\n";
        }else{
            int k;
            cin>>k;
            k--;
            ver.push_back(ver[k]);
        }
    }
}