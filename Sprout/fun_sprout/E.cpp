#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int md = 1e9+7;
signed main(){
    nono_is_handsome

    int n, m, y0=0;
    cin>>m>>n;

    int y = m*(m+1)/2%md;
    int x = n*(n+1)/2%md;
    int z=0;
    for(int i=m;i<=m+n-2;i++){
        z = (z + i*(i+1)/2)%md;
    }
    cout<<x*(y+z)%md<<'\n';
}