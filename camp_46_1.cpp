#include <iostream>

using namespace std;
int n,m,w[21],p[21],ans=0, sumP=0, sumW=0;
void dfs(int i){
    if(i==n){
        ans=max(ans, sumP);
    }else{
        dfs(i+1);
        if(sumW+w[i]<=m){
            sumP+=p[i];
            sumW+=w[i];
            dfs(i+1);
            sumW-=w[i];
            sumP-=p[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>m>>n;
    for (int i=0; i<n; i++){
        cin>>w[i]>>p[i];
    }
    dfs(0);
    cout<<ans<<"\n";
    return 0;
}