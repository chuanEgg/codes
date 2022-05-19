#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    while(q--){
        int temp;
        cin >> temp;
        int l=0, r=n;
        while(l < r){
            int m=(l+r)/2;
            if(s[m] > temp){
                r=m;
            }else{
                l=m+1;
            }
            // cout << s[m]<<"\n";
        }
        cout << l <<"\n";
    }
}