#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 2e5+10;
string s;
int dp[maxn][maxn], p[maxn][maxn];

int bruh(int i, int j){
    if(i == j) return 1;
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == s[j])
        dp[i][j] = bruh(i+1, j-1)+2, p[i][j] = 0;
    else if(bruh(i+1, j) > bruh(i, j-1))
        dp[i][j] = bruh(i+1, j), p[i][j] = 1;
    else if(bruh(i+1, j) < bruh(i,j-1))
        dp[i][j] = bruh(i, j-1), p[i][j] = 2;
    else    dp[i][j] = bruh(i,j-1), p[i][j] = 2;
    return dp[i][j];
}
void print(int i, int j){
    if(i>j) return;
    if(i == j)
        cout<<s[i];
    else if(p[i][j] == 0)
        cout<<s[i], print(i+1, j-1);
    else if(p[i][j] == 1)
        print(i+1, j);
    else
        print(i,j-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>s;
    int len = strlen(s);
    print(0,len-1);
}