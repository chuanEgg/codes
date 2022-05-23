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
    vector<int> v(n+1);
    for(int i=1; i<n; i++){
        int temp;
        cin>>temp;
        v[temp] =1;
    }
    for(int i=1; i<=n; i++){
        if(!v[i]){
            cout<<i<<"\n";
        }
    }
}