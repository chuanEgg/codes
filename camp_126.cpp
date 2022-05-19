#include <iostream>

using namespace std;

const int maxn= 1000001;
int s[maxn];
int dpN[maxn], dpM[maxn], dpQ[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>s[i];
    dpN[0]=0, dpM[0]=0, dpQ[0]=0, s[0]=0;
    for(int i=1; i<=n; i++){
        dpN[i]=max(dpM[i-1], dpQ[i-1])-s[i];
        dpM[i]=max(dpQ[i-1], dpN[i-1]);
        dpQ[i]=max(dpM[i-1], dpN[i-1])+s[i];
    }
    cout<<max(max(dpN[n], dpM[n]), dpQ[n])<<"\n";
}