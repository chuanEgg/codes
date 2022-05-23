#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char m[52][52];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<=n+1; i++){
            for(int j=0; j<=n+1; j++)
            {
                m[i][j] = '1';
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin>>m[i][j];   
            }
        }
        bool flag = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                //cout<<m[i][j]<<" ";
                if(m[i][j] == '1'){
                    if(m[i+1][j]!='1' && m[i][j+1]!='1'){
                        flag = 0;
                    }
                }
            }
            //cout<<"\n";
        }
        cout<<(flag?"YES\n":"NO\n");
    }
}