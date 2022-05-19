#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    int i = 0, j = 0;
    while(i<n && j<m){
        if(a[i] <= b[j]){
            cout << a[i]<<" ";
            i++;
        }else{
            cout << b[j] <<" ";
            j++;
        }
    }
    for(int k=i; k<n; k++){
        cout << a[k] <<" ";
    }
    for(int k=j; k<m; k++){
        cout << b[k] <<" ";
    }
}