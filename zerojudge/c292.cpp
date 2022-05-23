#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int s[52][52];
bool walked[52][52];
int dx[4] ={0,-1,0,1};
int dy[4] ={-1,0,1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int k;
    cin>>k;
    memset(walked,0,sizeof(walked));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>s[i][j];
        }
    }
    int x = (n+1)/2;
    int y = (n+1)/2;
    int cnt = 1;
    cout<<s[x][y];
    int pos = 1, temp = 0;
    while(cnt < n*n){
        for(int i=0; i<pos; i++){
            x += dx[k];
            y += dy[k];
            cout<<s[x][y];
            cnt++;
            if(cnt == n*n) break;
        }
        temp++;
        if(temp%2==0){
            pos++;
        }
        k = (k+1)%4;
    }
    cout<<"\n";
}