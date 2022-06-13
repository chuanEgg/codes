#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+5;
int s[maxn], tag[maxn * 4], tag2[maxn * 4];
struct node{
    int cnt[4]{0};
    node(){}
    node(int a){
        cnt[a] = 1;
    }
}tr [maxn * 4];

node operator+(const node& a, const node& b){
    node res;
    res.cnt[1] = a.cnt[1] + b.cnt[1];
    res.cnt[2] = a.cnt[2] + b.cnt[2];
    res.cnt[3] = a.cnt[3] + b.cnt[3];
    return res;
}
node combine(node a, node b){
    return a + b;
}
node operator+(const node& a, const int& b){
    node res;
    if(b % 3 == 1){
        res.cnt[2] += a.cnt[1];
        res.cnt[3] += a.cnt[2];
        res.cnt[1] += a.cnt[3];
    }else{
        res.cnt[1] += a.cnt[2];
        res.cnt[2] += a.cnt[3];
        res.cnt[3] += a.cnt[1];
    }
    return res;
}
void build(int idx, int l, int r){
    if(l == r){
        tr[idx].cnt[s[l]] = 1;
    }else{
        int m = (l+r)/2;
        build(idx*2+1, m+1, r);
        build(idx*2, l, m);
        tr[idx] = combine(tr[idx*2], tr[idx*2+1]);
    }
}
void push(int idx){
    if(tag[idx]){
        tr[idx<<1] = tr[idx<<1] + tag[idx];
        tr[idx<<1|1] = tr[idx<<1|1] + tag[idx];
        tag[idx<<1] += tag[idx];
        tag[idx<<1|1] += tag[idx];
        tag[idx] = 0;
    }
    if(tag2[idx]){
        tr[idx<<1].cnt[1] += tr[idx<<1].cnt[2] + tr[idx<<1].cnt[3];
        tr[idx<<1].cnt[2] = tr[idx<<1].cnt[3] = 0;
        tr[idx<<1|1].cnt[1] += tr[idx<<1|1].cnt[2] + tr[idx<<1|1].cnt[3];
        tr[idx<<1|1].cnt[2] = tr[idx<<1|1].cnt[3] = 0;
        tag2[idx<<1] = tag2[idx];
        tag2[idx<<1|1] = tag2[idx];
        tag2[idx] = 0;
    }
}
void add(int ql, int qr, int idx, int l, int r, int val){
    if(l!=r) push(idx);
    if(ql <= l && r <= qr){
        tr[idx] = tag[idx] + val;
        tag[idx] = val;
        return;
    }
    int m = (l+r)/2;
    if(ql <= m){
        add(ql, qr, idx<<1, l, m, val);
    }
    if(qr > m){
        add(ql, qr, idx<<1|1, m+1, r, val);
    }
    tr[idx] = combine(tr[idx<<1], tr[idx<<1|1]);
}
void update(int ql, int qr, int idx, int l, int r){
    if(l!=r) push(idx);
    if(ql <= l && r <= qr){
        tr[idx].cnt[1] += tr[idx].cnt[2] + tr[idx].cnt[3];
        tr[idx].cnt[2] = 0;
        tr[idx].cnt[3] = 0;
        tag2[idx] = 1;
        return;
    }
    int m = (l+r)/2;
    if(ql <= m){
        update(ql, qr, idx<<1, l, m);
    }
    if(qr > m){
        update(ql, qr, idx<<1|1, m+1, r);
    }
    tr[idx] = combine(tr[idx<<1], tr[idx<<1|1]);
}

node query(int ql, int qr, int idx, int l, int r){
    if(l!=r) push(idx);
    if(ql <= l && r <= qr)  
        return tr[idx];
    int m = (l+r)/2;
    if(m < ql)
        return query(ql, qr, idx << 1|1, m + 1, r);
    if(m >= qr)
        return query(ql, qr, idx << 1, l, m);
    return combine(query(ql, qr, idx << 1, l, m), query(ql, qr, idx << 1|1, m + 1, r));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    fill(s, s+n, 1);
    build(1, 0, n-1);
    while(m--){
        string o;
        int a, b;
        cin >> o >> a >> b;
        a-- ,b--;
        if(o[0] == 'T'){
            add(a, b, 1, 0, n-1, 1);
        }else if(o[0] == 'C'){
            node res = query(a, b, 1, 0, n-1);
            cout << res.cnt[1] <<'\n';
        }else{
            update(a, b, 1, 0, n-1);
        }
        // for(int i=0; i<n; i++){
        //     node temp = query(i, i, 1, 0, n-1);
        //     for(int j=1; j<=3; j++)
        //     {
        //         cout << temp.cnt[j] << " ";
        //     }
        //     cout << " ("<< i << ")\n";
        // }
        // node temp = query(a, b, 1, 0, n-1);
        // for(int j=1; j<=3; j++)
        // {
        //     cout << temp.cnt[j] << " ";
        // }
        // cout << "(a/b)\n";
        // temp = query(0, n-1, 1, 0, n-1);
        // for(int j=1; j<=3; j++)
        // {
        //     cout << temp.cnt[j] << " ";
        // }
        // cout << "(all)\n";

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                node temp = query(i, j, 1, 0, n-1);
                for(int j=1; j<=3; j++)
                {
                    cout << temp.cnt[j] << " ";
                }
                cout << " "<<i << ' '<<j<<"\n";
            }
        }
    }
}