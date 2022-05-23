#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 3001;
int dp[maxn][maxn];
int prevpos[maxn][maxn];
int len1, len2;
string s1, s2;

void print(int i, int j){
    if(i==0 || j==0){
        return;
    }
    if (prevpos[i][j] == 0)
    {
        print(i-1, j-1);
        cout << s1[i-1];
    }
    else if (prevpos[i][j] == 1)
        print(i, j-1);
    else if (prevpos[i][j] == 2)
        print(i-1, j);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>s2;
    len1 = s1.length();
    len2 = s2.length();
    memset(dp,0, sizeof(dp));
    memset(prevpos, -1, sizeof(prevpos));
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                prevpos[i][j] = 0;
            }else{
                if(dp[i][j-1] > dp[i-1][j]){
                    dp[i][j] = dp[i][j-1];
                    prevpos[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j];
                    prevpos[i][j] = 2;
                }
            }
        }
    }
    //cout<<dp[len1][len2]<<"\n";
    print(len1, len2);
}
