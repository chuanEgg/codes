#include <iostream>
#include <cstring>

using namespace std;
#define legal i+dy[k]>0&&i+dy[k]<=n&&j+dx[k]>0&&j+dx[k]<=m 
int m,n,ans;
int s[25][25];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m ;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
}
void sum(int i, int j, int last, bool changed[25][25]){
    if(changed[i][j]) return;
    int temp = 0, temp2 = 2;
    //print();
    //cout<<i<<"\t"<<j<<"\n";
    for(int k=0; k<4; k++){
        if(legal&&s[i+dy[k]][j+dx[k]]!=s[i][j]){
            temp++;
        }
    }
    s[i][j] = !s[i][j];
    //print();
    changed[i][j]=1;
    for(int k=0; k<4; k++){
        if(legal&&s[i+dy[k]][j+dx[k]]!=s[i][j]){
            temp2++;
        }
    }
    if(temp2>temp) return;
    //cout<<last<<" "<<temp<<" "<<temp2<<" ";
    last+=(temp2-temp);
    //cout<<last<<'\n';
    ans = min(ans, last);
    for(int a=1; a<=n; a++){
        for(int b=1; b<=m; b++){
            sum(a,b,last,changed);
            s[a][b]=!s[a][b];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int temp=0;
    ans = 1e5;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>s[i][j];
            if(i-1>0 && s[i-1][j] != s[i][j])
                temp++;
            if(j-1>0 && s[i][j-1] != s[i][j])
                temp++;
        }
    }
    //cout<<temp<<"\n";
    ans = temp;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            bool x[25][25]={0};
            sum(i,j,temp,x);
            s[i][j]=!s[i][j];
        }
    }
    cout<<ans<<"\n";
}