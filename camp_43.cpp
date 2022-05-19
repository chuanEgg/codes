#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> q;
vector<bool> chkC, chkD1, chkD2;

void dfs(int i){//某行
    if(i==n){
        //output
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                cout<<((q[r]==c)?"Q":"*");
            }
            cout<<"\n";
        }
        cout<<"\n";
    }else{
        for(int c=0; c<n; c++){//一列一隻
            int d1=i+c, d2=i-c+n-1;//對角線編號
            if(!chkC[c]&&!chkD1[d1]&&!chkD2[d2]){//是否填過
                q[i]=c;
                chkC[c]=chkD1[d1]=chkD2[d2]=1;
                dfs(i+1);//下一步
                q[i]=-1;
                chkC[c]=chkD1[d1]=chkD2[d2]=0;//還原
            }
        }
    }
}
int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    //初始
    q=vector<int>(n,-1);
    chkC.resize(n);
    chkD1.resize(n*2-1);
    chkD2=chkD1;
    dfs(0);
}