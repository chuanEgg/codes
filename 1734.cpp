#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+5;
int k, cnt[maxn], temp;
vector<int> s;
struct S{
    int l,r,id;
	bool operator < (const S b){
		return (l/k == b.l/k ? r < b.r : l/k < b.l/k);
	}
};
void del(int pos){
    --cnt[s[pos]];
	if(!cnt[s[pos]])
        temp--;
}
void add(int pos){
    if(!cnt[s[pos]])
        temp++;
	cnt[s[pos]]++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    k = sqrt(n)+1;
    s.resize(n+1);
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    auto v = s;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(),v.end())-v.begin()); 
    for(int i=1; i<=n; i++){
        s[i] = lower_bound(v.begin(),v.end(),s[i])-v.begin();
    }
    vector<S> q;
    vector<int> ans(m);
    for(int i=0; i<m; i++){
        int l, r;
        cin >> l >> r;
        q.push_back({l, r, i});
    }
    sort(q.begin(), q.end());
    int l=1, r=0;
    for(auto i:q){
        while(l < i.l) del(l++);
		while(l > i.l) add(--l);
		while(r < i.r) add(++r);
		while(r > i.r) del(r--);
		ans[i.id] = temp;
    }
    for(int i:ans){
        cout << i <<"\n";
    }
}