#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int solve(const string s, char c){
    if(s.size()==1){
        return s[0]!=c;
    }
    int cntl = solve(s.substr(0, s.size()/2), c+1) + s.size()/2;
    for(int i=s.size()/2; i<s.size(); i++){
        if(s[i]==c) cntl--;
    }
    int cntr = solve(s.substr(s.size()/2, s.size()/2), c+1) +s.size()/2;
    for(int i=0; i<s.size()/2; i++){
        if(s[i]==c) cntr--;
    }
    return min(cntl, cntr);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        cout<<solve(s,'a')<<"\n";
    }
}