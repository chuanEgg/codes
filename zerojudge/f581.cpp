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
    vector<int> q(m);
    vector<int> pre(2*n+1);
    for(int i=0; i<n; i++){
        cin>>room[i];
        if(i) pre[i] = pre[i-1]+room[i];
        else pre[i] = room[i];
    }
    for(int i=n; i<2*n; i++){
        pre[i] = pre[n-1]+pre[room[i-n]];
    }
    for(int i=0; i<m; i++){
        cin>>q[i];
    }
    int pos = 0, i=0;
    int temp = 0;
    while(i!=m){
        auto it =upper_bound(pre.begin()+pos, pre.end(), pre[pos-1]+q[i]);
        pos = it-pre.begin();
        pos%=n;
        i++;
        cout<<pos<<"\n";
    }
    cout<<pos<<"\n";
}