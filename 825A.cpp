#include <iostream>

using namespace std;

int n;
char s[90];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='1') cnt++;
        if(s[i]=='0'){
            cout<<cnt;
            cnt = 0;
        }
        if(i==(n-1))
            cout<<cnt<<"\n";
    }
}