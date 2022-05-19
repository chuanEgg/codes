#include <iostream>
#include <vector>

using namespace std;

int n, m;
long long cnt=0;
vector<bool> chkC, chkD1, chkD2, chkD1Q, chkD2Q;

void dfs(int i, int j){//某行
    if(j>m||(i-j)>n) return;
    if(i==n+m&&j==m){
        cnt++;
        //cout<<i<<" "<<j<<"\n";
    }else{
        for(int c=0; c<n+m; c++){
            int d1=i+c, d2=i-c+(n+m)-1;
            if(!chkC[c]&&!chkD1[d1]&&!chkD2[d2]){
                if((n+j-i)>0&&!chkD1Q[d1]&&!chkD2Q[d2]){
                    chkC[c]=chkD1[d1]=chkD2[d2]=1;
                    dfs(i+1,j);
                    chkC[c]=chkD1[d1]=chkD2[d2]=0;
                   // cout<<"Q "<<i<<" "<<j<<"\n";
                }
                chkC[c]=chkD1Q[d1]=chkD2Q[d2]=1;
                dfs(i+1,j+1);
                chkC[c]=chkD1Q[d1]=chkD2Q[d2]=0;
                //cout<<"C "<<i<<" "<<j<<"\n";
                //cout<<i<<"\n";
            }
        }
    }
}

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    //初始
    
    chkC.resize(n+m);
    chkD1.resize((n+m)*2-1);
    chkD2=chkD1Q=chkD2Q=chkD1;
    dfs(0,0);
    cout<<cnt<<"\n";
}