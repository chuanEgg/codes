#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    cin.get();
    while(t--){
        string s;
        getline(cin, s);
        int n = sqrt(s.length());
        if(n*n != s.length()){
            cout<<"INVALID\n";
            continue;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<s.length(); j+= n){
                cout<<s[i+j];
            }
        }
        cout<<"\n";
    }
}