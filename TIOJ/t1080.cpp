#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int maxn = 1e5+5;
int bit[maxn];
void update(int val, int pos){
    while(pos < maxn){
        bit[pos] += val;
        pos += pos&(-pos);
    }
}
int query(int pos){
    int res = 0;
    while(pos > 0){
        res += bit[pos];
        pos -= pos&(-pos);
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int cnt = 0;
    while(cin >> n && n){
        memset(bit, 0, sizeof(bit));
        cnt ++;
        vector<int> s(n), val(n);
        int ans = 0;
        for(int i=0; i<n; i++){
            cin>>val[i];
            s[i] = val[i];
        }
        sort(s.begin(), s.end());
        s.resize(unique(s.begin(), s.end()) - s.begin());
        for(int i=0; i<n; i++){
            int id = lower_bound(s.begin(), s.end(), val[i])-s.begin()+1;
            ans += i-query(id);
            update(1, id);
        }
        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
    }
}