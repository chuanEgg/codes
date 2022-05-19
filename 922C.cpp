#include <iostream>
#include <cstring>
#define int long long
using namespace std;
bool s[50];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(s,0,sizeof(s));
    int n,k;
    cin>>n>>k;
    if(k>=50){
        cout<<"No\n";
        exit(0);
    }
    for(int i=1; i<=k; i++){
        if(s[(n%i)]){
            cout<<"No\n";
            exit(0);
        }
        s[(n%i)] = 1;
    }
    cout<<"Yes\n";
}