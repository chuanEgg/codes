#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> chkR, chkC, chkB;
vector<int> g(81);

void solve(int i){
    if(i==81){
        for(int j=0; j<81; j++){
            cout<<g[j];
        }
        cout<<"\n";
        exit(0);
    }else if(g[i]){
        solve(i+1);
    }else{
        int R=i/9, C=i%9, B=R/3*3+C/3;
        for(int j=1; j<=9; j++){
            if(!chkR[R][j]&&!chkC[C][j]&&!chkB[B][j]){
                g[i]=j;
                chkR[R][j]=chkC[C][j]=chkB[B][j]=true;
                solve(i+1);
                g[i]=0;
                chkR[R][j]=chkC[C][j]=chkB[B][j]=false;
            }
        }
    }
}
int main()
{
    cin.tie(0),cout.tie(0);
    ios_base::sync_with_stdio(false);
    chkB.resize(9);
    for(int i=0; i<9; i++){
        chkB[i].resize(10);
    }
    chkR=chkC=chkB;
    string s;
    cin>>s;
    bool pass=1;
    for(int i=0; i<81; i++){
        if(s[i]=='.'){
            g[i]=0;
        }else{
            int t=s[i]-'0';
            int R=i/9, C=i%9, B=R/3*3+C/3;
            if(chkR[R][t]||chkC[C][t]||chkB[B][t]){
                pass=0;
                break;
            }
            g[i]=t;
            chkR[R][t]=chkC[C][t]=chkB[B][t]=true;
        }
    }
    if(pass){
        solve(0);
    }
    cout<<"No solution.\n";
    return 0;
}