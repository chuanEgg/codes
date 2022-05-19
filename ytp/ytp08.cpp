#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string s[n+1];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    for(int i=0; i<m; i++){
        bool pass=1;
        int a,b;
        cin>>a>>b;
        int j=0;
        while(s[a][j]==s[b][j]&&(j+1)<=min(s[a].length(), s[b].length())){
            j++;
        }
        cout<<j<<"\n";
    }
}