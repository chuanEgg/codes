#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int s[n];
    int temp=0,sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int in;
            cin>>in;
            temp=max(temp, in);
        }
        s[i]=temp;
        temp=0;
        sum+=s[i];
    }
    cout<<sum<<"\n";
    bool pass=0;
    for(int i=0; i<n; i++){
        if(sum%s[i]==0){
            cout<<s[i]<<" ";
            pass=1;
        }
    }
    if(!pass) cout<<"-1";
    cout<<"\n";
}