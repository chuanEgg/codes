#include <iostream>
#include <vector>
#pragma GCC optimize("Ofast")

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v[n];
    int t, a;
    for(int i=0; i<n; i++){
        cin>>t;
        for(int j=0; j<t; j++){
            cin>>a;
            v[i].push_back(a);
        }
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>a;
        a--;
        for(auto j:v[a]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}