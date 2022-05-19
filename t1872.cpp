#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>

#define fidx mono[x].front().idx
#define fi mono[x].front().i
#define fj mono[x].front().j
#define int long long
using namespace std;

const int maxn = 1e6+5;
const int mod = 1e9+7;
const int primeCount = 8e5;
int lpf[maxn], s[maxn], ans[maxn];
int bit[maxn];
int n,q;
vector<int> prime;
vector<pair<int,int>> Q[maxn];
struct S{
    int idx, i, j;
    S(int a, int b, int c){
        idx = a;
        i = b;
        j = c;
    }
   
};
deque<S> mono[maxn];
// mono[i].idx -> 某質數 i 的次方
// mono[i].i/j -> 位置

void eratosthenes(){
    for(int i = 2; i<maxn; i++){
        if(lpf[i] == 1){
            prime.push_back(i);
        }
        for(int p:prime){
            if(i*p >= maxn)
                break;
            lpf[i*p] = p;
        }
    }
}
int fastpow(int x, int t){
    int res = 1;
    while(t > 0){
        if(t&1){
            res = res*x%mod;
        }
        x = x*x % mod;
        t>>=1;
    }
    return res%mod;
}
int query(int i){
    int res = 1;
    while(i){
        res *= bit[i];
        res %= mod;
        i -= i&(-i);
    }
    return res % mod;
}
void update(int i, int val){
    while(i<maxn){
        bit[i] *= val;
        bit[i] %= mod;
        i += i&(-i);
    }
}

void handle(int x, int cnt, int pos){
    // cout<<s[pos]<<"\t"<<x<<"\t"<<cnt<<'\t'<<fidx<<"\n";
    while(!mono[x].empty() && fidx <= cnt){
        update(fi, fastpow(fastpow(x, fidx),mod-2));
        update(fj, fastpow(x, fidx));
        mono[x].pop_front();
        // cout<<fidx<<"\n";
    }
    if(mono[x].empty()){
        update(pos, fastpow(x, cnt));
        update(n+1, fastpow(fastpow(x, cnt),mod-2));
        mono[x].push_front(S(cnt, pos, n+1));
        // cout<<pos<<"\t"<<n+1<<"\n";
    }else{
        update(pos, fastpow(x, cnt));
        update(fi, fastpow(fastpow(x, cnt),mod-2));
        // cout<<"\t"<<fi<<"\t"<<fastpow(fastpow(x, cnt),mod-2)%mod<<"\n";
        mono[x].push_front(S(cnt, pos, fi));
    }
    
    // cout<<query(n)<<"\n";
}
void factorize(int x, int pos){
    int cur = 0, cnt = 0;
    while(lpf[x] != 1){
        // cout<<lpf[x]<<"\n";
        if(lpf[x] == cur){
            cnt++;
        }else {
            if(cnt)
                handle(cur,cnt,pos);
            cur = lpf[x];
            cnt = 1;
        }
        x /= lpf[x];
    }
    if(x == cur){
            cnt++;
    }else {
        if(cnt)
            handle(cur,cnt,pos);
        cur = x;
        cnt = 1;
    }
    handle(cur, cnt,pos);
    // return factor;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(lpf, lpf+maxn, 1);
    fill(bit, bit+maxn, 1);
    eratosthenes();
    // cout<<prime.size()<<"\n";
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        Q[l].push_back({r,i});
    }
    for(int i=n; i>=1; i--){
        // cout<<s[i]<<"\n";
        factorize(s[i],i);
        // for(auto p:temp){
        //     cout<<p.first<<"\t"<<p.second<<"\n";
        // }
        for(auto j:Q[i]){
            ans[j.second] = query(j.first);
        }
    }
    for(int i=0; i<q; i++){
        cout<<ans[i]<<"\n";
    }
}