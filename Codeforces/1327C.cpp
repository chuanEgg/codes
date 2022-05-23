#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int d[k+1][2];
    int s[k+1][2];
    for(int i=0; i<k; i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=0; i<k; i++){
        cin>>d[i][0]>>d[i][1];
    }
    cout<<n*m+n+m-3<<"\n";
    for(int i=0; i<(n-1); i++)  cout<<"U";
    for(int i=0; i<(m-1); i++)  cout<<"L";
    for(int i=0; i<n; i++){
        if(i!=0)
            cout<<"D";
        if(i%2==0)
            for(int j=0; j<(m-1); j++){
                cout<<"R";
            }
        else
            for(int j=0; j<(m-1); j++){
                cout<<"L";
            }
    }
}