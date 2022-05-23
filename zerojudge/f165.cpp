#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    if(k==0 || !(n%k)) cout<<"OK!\n";
    else cout<<n%k<<"\n";
}