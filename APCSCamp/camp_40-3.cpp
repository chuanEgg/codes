#include <iostream>

using namespace std;

long long H(int n, int m){
    //(n+m-1)!/m!*(n-1)!
    long long ans=1;
    for(int i=(n+m-1); i>=(n-2*m); i++){
        ans*=i;
    }
    for(int i=1; i<=m; i++){
        ans/=i;
    }
    ans%=998244353;
    return ans;
}
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout<<H(n,m-6*n)<<"\n";
    }
}