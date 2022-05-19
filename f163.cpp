#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e6+3;
int l[maxn<<1], r[maxn<<1], p[maxn<<1], q[10001], s[maxn<<1];
int sum[maxn<<1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(sum,0,sizeof(sum));
    int n,m;
    cin>>n>>m;
    for(int i=n; i<(2*n); i++){
        cin>>sum[i];
    }
    for(int i=0; i<m; i++){
        cin>>q[i];
    }
    for(int i=0; i<n; i++){
        int f,L,R;
        cin>>f>>L>>R;
        l[f] = L;
        r[f] = R;
        p[L] = f;
        p[R] = f;
    }
    //cout<<"hi\n";
    // for(int i=n; i<2*n; i++) cout<<p[i]<<" ";
    // cout<<"\n";
    for(int i = n; i<2*n; i++){
        int pos = p[i];
        while(pos!=1){
            // cout<<pos<<"\n";
            sum[pos] += sum[i];
            pos = p[pos];
        }
    }
    
    int pos = 1;
    for(int i=0; i<m; i++){
        while(pos <= (n-1)){
            if(sum[l[pos]] <= sum[r[pos]]){
                pos = l[pos];
                sum[pos]+=q[i];
            }else{
                pos = r[pos];
                sum[pos]+=q[i];
            }
        }
        cout<<pos<<" ";
        pos = 1;
    }
    cout<<"\n";
}