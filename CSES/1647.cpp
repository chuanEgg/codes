#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5+5;
const int log = 18;
int s[maxn], t[log][maxn], l[maxn];
void build(){
    for(int i=0; i<maxn; i++){
        t[0][i] = s[i];
    }
    for(int i=1; (1<<i)<=maxn; i++){
        for(int j=0; j+(1<<i)<=maxn; j++){
            t[i][j] = min(t[i-1][j], t[i-1][j+(1<<(i-1))]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(t,0x3f,sizeof(t));
    memset(s,0x3f,sizeof(s));
    l[1] = 0;
    for(int i=2; i<=maxn; i++){
        l[i] = l[i/2]+1;
    }
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    build();
    while(m--){
        int ll,r;
        cin>>ll>>r;
        int j = l[r-ll+1];
        int minimum = min(t[j][ll], t[j][r-(1<<j)+1]);
        cout<<minimum<<"\n";   
    }
}