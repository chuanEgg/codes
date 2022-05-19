#include <iostream>
#include <cstring>

using namespace std;

const int N = 101, W = 100001;
int cost[N], weight[N];
long long int c[N+1][W+1];
int n,w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>w;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>cost[i];
    }
    memset(c,0,sizeof(c));
    for (int i=0; i<n; i++)
        for (int j=0; j<=w; j++)
            if (j-weight[i]<0)
                c[i+1][j] = c[i][j];
            else
                c[i+1][j] = max(c[i][j],c[i][j-weight[i]]+cost[i]);
    cout<<c[n][w]<<"\n";
}