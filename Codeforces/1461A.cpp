#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        for(int i=0; i<k; i++){
            cout<<"a";
        }
        for(int i=1; i<=(n-k); i++){
            cout<<(char)('a'+i %3);
        }
        cout<<"\n";
    }
}