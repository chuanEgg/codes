#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int paper[105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>paper[i][j];
        }
    }
    int l = 0,r = m-1,u = 0,d = n-1;
    while(t--){
        string op;
        int k;
        cin>>op>>k;
        if(op == "R"){
            for(int i=u; i<=d; i++){
                for(int j=1; j<=k; j++){
                    paper[i][r-k-j+1] += paper[i][r-k+j];
                    paper[i][r-k+j] = 0;
                }
            }
            r-=k;
        }else if(op == "L"){
            for(int i=u; i<=d; i++){
                for(int j=1; j<=k; j++){
                    paper[i][l+k+j-1] += paper[i][l+k-j];
                    paper[i][l+k-j] = 0;
                }
            }
            l+=k;
        }else if(op == "D"){
            for(int i=l; i<=r; i++){
                for(int j=1; j<=k; j++){
                    paper[d-k-j+1][i] += paper[d-k+j][i];
                    paper[d-k+j][i] = 0; 
                }
            }
            d-=k;
        }else if(op == "U"){
            for(int i=l; i<=r; i++){
                for(int j=1; j<=k; j++){
                    paper[u+k+j-1][i] += paper[u+k-j][i];
                    paper[u+k-j][i] = 0; 
                }
            }
            u+=k;
        }else if(op == "LU"){
            for(int i=u; i<(u+k); i++){
                int j=l+k-(i-u);
                //cout<<i<<" "<<j<<"\n";
                for(int a=1; a<=k && (i+a)<=d && (j-a)>=l; a++){
                    paper[i+a][j] += paper[i][j-a];
                    paper[i][j-a] = 0;
                    //cout<<"\t"<<i<<" "<<j-a<<"\n";
                }
            }
        }else if(op == "LD"){
            for(int j=l; j<=(l+k); j++){
                int i=d-k+(j-l);
                for(int a=1; a<=k && (j+a)<=r && (i+a)<=d; a++){
                    paper[i][j+a] += paper[i+a][j];
                    paper[i+a][j] = 0;
                }
            }
        }else if(op == "RU"){
            for(int i=u; i<=(u+k); i++){
                int j=r-k+(i-u);
                for(int a=1; a<=k && (i+a)<=d && (j+a)<=r; a++){
                    paper[i+a][j] += paper[i][j+a];
                    paper[i][j+a] = 0;
                }
            }
        }else if(op == "RD"){
            for(int j=r; j>=l; j--){
                int i=d-k+(r-j);
                //cout<<i<<" "<<j<<"\n";
                for(int a=1; a<=k && (j-a)>=l && (i+a)<=d; a++){
                    paper[i][j-a] += paper[i+a][j];
                    paper[i+a][j] = 0;
                }
            }
        }
    }
    cout<<d-u+1<<" "<<r-l+1<<"\n";
    for(int i=u; i<=d; i++){
        for(int j=l; j<=r; j++){
            cout<<paper[i][j]<<" ";
        }
        cout<<"\n";
    }
}