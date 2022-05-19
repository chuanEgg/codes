#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n<=3 && n>1){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    for(int i=2; i<=n; i+=2){
        cout<<i<<" ";
    }
    for(int i=1; i<=n; i+=2){
        cout<<i<<" ";
    }
    cout<<"\n";
}