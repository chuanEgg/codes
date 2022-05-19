#include <iostream>
#include <vector>

using namespace std;

#define lowbit(x) (x & -x)
#define ll long long
const int N= 2000001;
int bit[N];
int n; 
long long int sum(int x){
	ll ret = 0;
	for (; x; x-=lowbit(x))
		ret+=bit[x];
	return ret;
}
void update(int x, int v){
	for (; x<=2*n; x+=lowbit(x))
		bit[x]+=v;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	ll ans=0;
	cin>>n;
	vector<int> l(n+1), r(n+1);
	for (int i=1,t; i<=2*n; i++) {
		cin>>t;
		if (!l[t]) l[t]=i;
		else r[t]=i;
	}
	for (int i=1; i<=n; i++) {
		ans +=sum(r[i])-sum(l[i]);
		update(l[i], 1), update(r[i], 1);
	}
	cout << ans << '\n';
}