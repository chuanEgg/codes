#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=(4*n); i>=(2*n+2); i-=2){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}