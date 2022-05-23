#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int u[8],d[8];
        for(int i=1; i<=7; i++){
            cin>>u[i];
        }
        for(int i=1; i<=7; i++){
            cin>>d[i];
        }
        bool a=0,b=0,c=0;
        if((u[2]!=u[4] && u[2]==u[6]) && (d[2]!=d[4] && d[2]==d[6]))
            a = 1;
        if(u[7]==1 && d[7]==0)
            b = 1;
        if(u[2]!=d[2] && u[4]!=d[4] && u[6]!=d[6])
            c = 1;
        if(!a)   cout<<"A";
        if(!b)   cout<<"B";
        if(!c)   cout<<"C";
        if(a&&b&&c) cout<<"None";
        cout<<"\n";
    }
}