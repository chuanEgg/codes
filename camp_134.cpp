#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s,r,back;
int len;
const int N = 2e5+10;
int dp[maxn][maxn], prevpos[maxn][maxn];

void print(int pos, int rpos);
void LCS(int l){
    for(int i=0; i<=l;i++) dp[i][0]=0;
    for(int i=0; i<=l;i++) dp[0][i]=0;
    for(int i=1; i<=l; i++){
        for(int j=1; j<=l; j++){
            if(s[i] == r[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                prevpos[i][j]=0;
            }else{
                if(dp[i-1][j]<dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                    prevpos[i][j]=1;
                }else{
                    dp[i][j]=dp[i-1][j];
                    prevpos[i][j]=2;
                }
            }
        }
    }
    print(l,l);
}
void print(int pos, int rpos){
    int i=pos, j=rpos;
    if(i==0||j==0) return;
    if(prevpos[i][j]==0){
        print(i-1,j-1);
        cout<<s[i];
        back+=s[i];
    }else if(prevpos[i][j]==1){
        print(i,j-1);
    }else{
        print(i-1,j);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>r;
    s=r;
    reverse(r.begin(), r.end());
    len=s.length();
    s=("0"+s);
    r=("0"+r);
    //cout<<r<<"\n"<<s<<"\n";
    if(len%2==0){
        LCS(len/2);
        for(int i=back.length()-1; i>=0; i--){
            cout<<back[i];
        }
    } 
    else{
        LCS(len/2+1);
        for(int i=back.length()-2; i>=0; i--){
            cout<<back[i];
        }
    }
}