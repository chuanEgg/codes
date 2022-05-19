#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> room(n+1);
    vector<int> sum(2*n+1);
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>room[i];
        sum[i] = sum[i-1]+room[i];
    }
    for(int i=n+1; i<=2*n; i++){
        sum[i] = sum[n] + sum[i-n];
    }

    // for(int i=0; i<=2*n; i++){
    //     cout<<sum[i]<<" ";
    // }cout<<endl;

    int pos = 1;
    int q;
    for(int i=0; i<m; i++){
        cin>>q;
        int temp = sum[pos-1];
        auto it = lower_bound(sum.begin()+pos, sum.end(), temp+q);
        pos = it-sum.begin();
        //cout<<pos<<"\n";
        pos%=n;
        pos++;
    }
    
    cout<<pos-1<<"\n";
}