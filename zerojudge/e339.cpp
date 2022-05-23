#include <iostream>

using namespace std;

int main(){
    //cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long int n,temp, num=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin>>temp;
        num+=temp;
        cout<<num<<" ";
    }
    cout<<"\n";
    return 0;
}