#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b<b+a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    sort(s,s+n, cmp);
    for(int i=0; i<n; i++){
        cout<<s[i];
    }
    cout<<"\n";
}