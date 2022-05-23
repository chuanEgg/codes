#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

int a,b,c,d,e,f;
int dp[100];
int g(int i){
    if(dp[i+50]) return dp[i+50];
    int ans;
    ans = a*(i*i*i*i*i) + b*(i*i*i*i) + c*(i*i*i) + d*(i*i) + e*i + f;
    return dp[i+50] = ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c>>d>>e>>f;
    if(!(a||b||c||d||e||f)){
        cout<<"Too many... = =\"";
        exit(0);
    }
    bool flag = 0;
    for(int i=-35; i<=35; i++){
        if(g(i) == 0){
            cout<<i<<" "<<i<<"\n";
            flag = 1;
        }else
        if((g(i)*g(i+1)) <= 0 && g(i+1) != 0){
            cout<<i<<" "<<i+1<<"\n";
            flag = 1;
        }

    }
    if(!flag) cout<<"N0THING! >\\\\\\<\n";
}