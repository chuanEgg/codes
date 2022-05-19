#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int j=0;
    for(int i=0; i<m; i++){
        cin>>b[i];
        while(j<n && a[j]<b[i]){
            j++;
        }
        cout<<j<<" ";
    }
}