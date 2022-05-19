#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 16;
int adj[maxn][maxn];
int dp[(1<<maxn)], cost[(1<<maxn)];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adj[i][j];
        }
    }
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(i & (1<<j) && i & (1<<k)){//(1<<j) is the j-th person
                    //j-th and k-th person are in the same group
                    cost[i] += adj[j][k];
                }
            }
        }
    }
    for(int i=0, j; i<(1<<n); i++){ //iterating thru all submasks
        j=((1<<n)-1)^i; //to ensure not to collide, the opposite of i
        for(int k=j; k; k=(k-1)&j){ 
            // iterate something in j
            dp[i^k]= max(dp[i^k], dp[i]+cost[k]); 
            //i^k -> combination of i and k
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
    //that is 11111...1 (n times)
}