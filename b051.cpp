#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b<b+a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        vector<string> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(), v.end(), cmp);
        for(int i=n-1; i>=0; i--){
            cout<<v[i];
        }
        cout<<"\n";
    }
}